#!/usr/bin/env python3

import evdev
from evdev import InputDevice, categorize, ecodes
from select import select
import time
import serial

VENDOR_ID = 0x05c7
PRODUCT_ID = 0x6004

# デバイスの一覧からvendorIDとproductIDを使って、テンキーとマウスのデバイスを見つける
devices = [evdev.InputDevice(path) for path in evdev.list_devices()]
device_paths = [device.path for device in devices if device.info.vendor == VENDOR_ID and device.info.product == PRODUCT_ID]

# 2つのデバイスが存在することを確認
if len(device_paths) != 2:
    raise Exception("Expected 2 devices but found " + str(len(device_paths)))

# event番号が小さい方がテンキー、大きい方がマウスとして処理
keypad_path = min(device_paths)
mouse_path = max(device_paths)

keypad = InputDevice(keypad_path)
mouse = InputDevice(mouse_path)

devices = [keypad, mouse]

# UARTの設定
uart = serial.Serial(
    port='/dev/serial0',
    baudrate=19200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

# オートリピートに関する変数
auto_repeat_start_time = {}  # キー押下時の時間を格納
repeat_delay = 0.5  # オートリピート開始までの遅延
repeat_interval = 0.1  # オートリピートの間隔

print("Listening to devices...")

while True:
    r, _, _ = select(devices, [], [], repeat_interval)
    for device in r:
        for event in device.read():
            msg = ""  # 送信メッセージを格納する変数
            # テンキーのイベント処理
            if device == keypad:
                if event.type == ecodes.EV_KEY:
                    key_event = categorize(event)
                    state = "pressed" if key_event.keystate == key_event.key_down else "released"
                    msg = f"Key {key_event.keycode} {state}\n"
                    if state == "pressed":
                        auto_repeat_start_time[key_event.keycode] = time.time()
                    elif state == "released" and key_event.keycode in auto_repeat_start_time:
                        del auto_repeat_start_time[key_event.keycode]
            # マウスのイベント処理
            elif device == mouse:
                if event.type == ecodes.EV_KEY:
                    state = "pressed" if event.value == 1 else "released"
                    msg = f"Mouse Button {evdev.ecodes.BTN[event.code]} {state}\n"
                # マウスの移動イベント処理
                elif event.type == ecodes.EV_REL:
                    if event.code == ecodes.REL_X:
                        msg = f"Mouse moved horizontally: {event.value}\n"
                    elif event.code == ecodes.REL_Y:
                        msg = f"Mouse moved vertically: {event.value}\n"
                    # マウスホイールの回転イベント処理
                    elif event.code == ecodes.REL_WHEEL:
                        direction = "down" if event.value > 0 else "up"
                        msg = f"Mouse wheel scrolled {direction}\n"
            
            # UART経由でメッセージをArduinoに送信
            if msg:
                uart.write(msg.encode())
                print(msg.strip())  # 標準出力にもメッセージを出力
    
    # オートリピートの処理
    current_time = time.time()
    for keycode, start_time in list(auto_repeat_start_time.items()):
        if current_time - start_time > repeat_delay:
            msg = f"Key {keycode} repeated\n"
            uart.write(msg.encode())
            print(msg.strip())  # 標準出力にもメッセージを出力
            auto_repeat_start_time[keycode] = current_time  # update the last repeat time
