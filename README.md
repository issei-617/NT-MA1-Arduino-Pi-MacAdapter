# NT-MA1-Arduino-Pi-MacAdapter
Enable both the mouse and ten-key functions of NT-MA1 (numeric keypad mouse, sanwasupply) for use on a Mac.

## Background
　The NT-MA1 (numeric keypad mouse) is a usb-connected HID (Human Interface Device) that combines a numeric keypad and mouse in one device. Unfortunately, the NT-MA1's mouse function can be used on a Mac, but not the numeric keypad function. I wanted to make it possible to use both mouse and numeric keypad functions, which I was able to achieve by asking ChatGPT.

## Caution
　This is not intended for practical use, but only as a trial.

## Plan
　When I connected the NT-MA1 to a Mac with ubuntu dual-boot installed, I could use the mouse and numeric keypad functions on the ubuntu. On the other hand, only the mouse function was usable on the MacOS. From this, I assumed that it was a software (device driver) problem, not a hardware problem. Then, it was too difficult for me to write a device driver for MacOS, so I gave up.

　Next, we considered attaching a usb host shield to a microcontroller with HID functionality (e.g., Arduino Leonardo), receiving NT-MA1 information with the usb hostshield, and sending data as HID to the PC via the Arduino Leonardo. In this case, I need to write my own library for receiving data via usb hostshield, which would require analyzing the usb communication between NT-MA1 and PC. It was too difficult for me and I gave up.

　When the NT-MA1 is connected to the Raspberry pi 3B+, both mouse and numeric keypad functions are available. Therefore, I adopted the method of using the Raspberrypi and Arduino together: the Raspberrypi receives data from the NT-MA1 and sends it to the Arduino via serial communication, and key emulation is performed in the Arduino based on that data.

## Environment
MacBook Pro (13-inch, 2016, Four Thunderbolt 3 Ports)
macOS: version 12.7

Arduino IDE: 1.8.19
Arduino Leonardo

Raspberry pi 3B +
Raspberry Pi OS Lite

## Preparation
　GUI (Graphical User Interface) is not necessary for raspberrypi on this task. Therefore, the OS to be installed on raspberrypi is Raspberrypi os lite, which is a CLI (Command Line Interface).

 There are I2C and UART as methods of serial communication between Arduino and Raspberrypi. UART was adopted as an easy method.

## Physical wiring diagrams and schematics

## Code on the Raspberrypi side

### How to get numeric keypad mouse information on raspberrypi
 I can use `evtest` commnad or reading `/dev/input/theInterface` directly for detecting mouse and key input, but since I wanted to write the Raspberrypi side code with Python, I decided to use `evdev` which is a library to receive key input in Python.

### Check the product ID and the vender ID of the NT-MA1.
 When `evdev` reads input from a device, it is necessary to specify which device it is reading from. Product ID and vendor ID can be used to identify the device, so check the product ID and the vendor ID with an appropriate tool. For NT-MA1, VENDOR_ID = 0x05c7 and PRODUCT_ID = 0x6004.

### Receiving data from multiple devices
 On `evdev`, input from the NT-MA1 numeric keypad and input from the mouse are treated as separate devices. Therefore, we have to write a program to wait for inputs from multiple devices. We decided to use `select` for this.

### How to keep monitoring data from the NT-MA1.
 ChatGPT proposed the following methods: (1) polling (looping and reading repeatedly), (2) multi-threading, and (3) multi-processing, all worked well. I decided to use the simplest method, polling.

### Realization of auto-repeat
 It is realized as follows: use Python's `time` module to get the current time and measure the time elapsed since the key was pressed. When a certain threshold is exceeded, it triggers auto-repeat and displays the key code.

## Code on Arduino side
 It's simple. Write code to emulate the key based on the data sent through uart.

## Usage

(1) Wire as above.
(2) Burn program() to Arduino Leonardo with Arduino IDE.
(3) Execute the program() on the Raspberrypi. Then, it starts monitoring the input from NT-MA1. (It is easier to connect to the Raspberrypi via ssh from the PC.)
(4) Open the serial monitor of Arduino IDE. As written in the code, the communication speed is 19200.



************************************

## 背景
　NT-MA1（テンキーマウス）はテンキーとマウスが一体になったusb接続のHID（Human Interface Device）である。残念ながらMacでは、NT-MA1のマウス機能は使えるが、テンキー機能は使えない。そこで、マウス機能もテンキー機能も使えるようにしたい。ChatGPTに聞きながら実現できた。

## 注意
　実用を目的としたものではなく、あくまで試しにやってみた程度のものである。

## 方針
　ubuntuをデュアルブートでインストールしたMacにNT-MA1を接続すると、ubuntuではマウス機能もテンキー機能も使えた。一方、MacOSの方では、マウス機能のみ使えた。このことから、ハードウェアの問題ではなく、ソフトウェア（デバイスドライバ）の問題と推測された。では、MacOS用のデバイスドライバを書けるかというと、私には難しすぎて、断念した。

　次に、HID機能を有するマイクロコントローラー（例:Arduino Leonardo）にusb host shieldを装着し、usb hostshieldでNT-MA1の情報を受け取り、Arduino Leonardoを介してPCへHIDとしてのデータを送ることを考えた。この場合、usb hostshieldでデータを受け取る際のライブラリを自分で書く必要があり、そのためにはNT-MA1とPC間のusb通信を解析する必要がある。私には難しすぎて、断念した。

　Raspberry pi 3B+ にNT-MA1を接続すると、マウス機能もテンキー機能も使える。そこでRaspberrypiとArduinoとを併用する方法を採用した。RaspberryipでNT-MA1のデータを受けとり、それをシリアル通信でArduinoへ送り、そのデータに基づきArduino内でキーエミュレーションする。

## 環境
MacBook Pro (13-inch, 2016, Four Thunderbolt 3 Ports)
macOS: version 12.7

Arduino IDE: 1.8.19
Arduino Leonardo

Raspberry pi 3B +
Raspberry Pi OS Lite

## 準備
　raspberrypiではGUI（Graphical User Interface）は不要。そこで、raspberrypiにインストールするOSは、CLI（Command Line Interface）であるRaspberrypi os liteにした。

　ArduinoとRaspberrypiとのシリアル通信の方法としてI2CやUARTがある。簡単な方法としてUARTを採用した。


## 実体配線図、回路図

## Raspberrypi側のコード

### raspberrypiでテンキーマウスの情報を取得する方法
`evtest` や `/dev/input/theInterface`を直接読む方法が考えられた。Raspberrypi側はPythonで書くので、Pythonのキー入力を受け取るライブラリである`evdev`を用いることにした。

### NT-MA1のproduct IDとventer IDを調べておく。
evdevでデバイスからの入力を読み取るときに、どのデバイスから読み取るかを指定する必要がある。product IDとvender IDとでデバイスを特定できる。適当なツールを用いてproduct IDとventer IDを調べておく。なお、NT-MA1はVENDOR_ID = 0x05c7、PRODUCT_ID = 0x6004であった。

### 複数デバイスからデータを受け取る
`evdev`上では、NT-MA1のテンキーからの入力とマウスからの入力は別のデバイスとして扱われる。したがって、複数デバイスからの入力を待ち受けるプログラムを書くことになる。これには`select`を用いることにした。

### マウスからのデータを監視し続ける方法。
ChatGPTからは（1）polling（ループして繰り返し読み取る）、（2）マルチスレッド、（3）マルチプロセスを用いた方法の提案があり、いずれも実現可能であった。最も単純なpollingを用いることにした。

### オートリピートの実現
以下のようにして実現した。Pythonの`time`モジュールを使用して現在の時刻を取得し、キーが押されてからの経過時間を測定する。一定の閾値を超えたらオートリピートをトリガーとして、そのキーコードを表示する。

## Arduino側のコード
uartを通じて送られてきたデータに基づき、キーをエミュレーションするコードを書く。


## 使い方

（1）上記のように配線する。
（2）　、、、をArduinoIDEからマイコンボードに書き込んでおく。
（3）Raspberrypiで、、、を実行する。するとNT-MA1からの入力の監視が始まる。（Raspberrypiへ母艦のPCからssh接続し、そこから、、、を実行すると楽である）。
（4）ArduinoIDEのシリアルモニタを開く。コード上に書いてある通り、通信速度は19200。すると、シリアルモニタ上にuartから受信したデータを表示するとともに、Mac上に文字が入力されたり、マウスポインタが移動したりする。

### 注意
マウスの動きはかなり鈍く、実用性に乏しい。

　



