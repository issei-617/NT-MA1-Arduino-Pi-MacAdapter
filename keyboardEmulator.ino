#include <Keyboard.h>
#include <Mouse.h>

// イベント識別子の定義
enum ExternalInput {
    // 他のすべてのイベント識別子をここにリストする
    KEY_NUMLOCK_PRESSED, KEY_NUMLOCK_RELEASED,
    KEY_KP1_PRESSED, KEY_KP1_RELEASED,
    KEY_KP2_PRESSED, KEY_KP2_RELEASED,
    KEY_KP3_PRESSED, KEY_KP3_RELEASED,
    KEY_KP4_PRESSED, KEY_KP4_RELEASED,
    KEY_KP5_PRESSED, KEY_KP5_RELEASED,
    KEY_KP6_PRESSED, KEY_KP6_RELEASED,
    KEY_KP7_PRESSED, KEY_KP7_RELEASED,
    KEY_KP8_PRESSED, KEY_KP8_RELEASED,
    KEY_KP9_PRESSED, KEY_KP9_RELEASED,
    KEY_KP0_PRESSED, KEY_KP0_RELEASED,
    KEY_KPDOT_PRESSED, KEY_KPDOT_RELEASED,
    KEY_KPENTER_PRESSED, KEY_KPENTER_RELEASED,
    KEY_KPPLUS_PRESSED, KEY_KPPLUS_RELEASED,
    KEY_KPMINUS_PRESSED, KEY_KPMINUS_RELEASED,
    KEY_BACKSPACE_PRESSED, KEY_BACKSPACE_RELEASED,
    KEY_KPASTERISK_PRESSED, KEY_KPASTERISK_RELEASED,
    KEY_KPSLASH_PRESSED, KEY_KPSLASH_RELEASED,
    KEY_INSERT_PRESSED, KEY_INSERT_RELEASED,
    KEY_DELETE_PRESSED, KEY_DELETE_RELEASED,
    KEY_END_PRESSED, KEY_END_RELEASED,
    KEY_DOWN_PRESSED, KEY_DOWN_RELEASED,
    KEY_PAGEDOWN_PRESSED, KEY_PAGEDOWN_RELEASED,
    KEY_LEFT_PRESSED, KEY_LEFT_RELEASED,
    KEY_RIGHT_PRESSED, KEY_RIGHT_RELEASED,
    KEY_HOME_PRESSED, KEY_HOME_RELEASED,
    KEY_UP_PRESSED, KEY_UP_RELEASED,
    KEY_PAGEUP_PRESSED, KEY_PAGEUP_RELEASED,
    MOUSE_LEFT_PRESSED,  MOUSE_LEFT_RELEASED,
    MOUSE_RIGHT_PRESSED,  MOUSE_RIGHT_RELEASED,
    MOUSE_MIDDLE_PRESSED,  MOUSE_MIDDLE_RELEASED,
    MOUSE_WHEEL_DOWN, MOUSE_WHEEL_UP,
    MOUSE_MOVE_V, MOUSE_MOVE_H
};

// グローバル変数
int move_v = 0;
int move_h = 0;



void setup() {
  // シリアル通信を開始
  Serial.begin(19200);
  Serial1.begin(19200);

  // キーボードとマウスのエミュレーションを開始
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  // 外部デバイスからの入力を読み取る (仮定)
  int input = readExternalInput();  // この関数は外部デバイスからの入力を読み取る
  //Serial.println(input);
  // 入力に応じてアクションを実行
  switch (input) {
    case KEY_NUMLOCK_PRESSED:
      Serial.println("Key KEY_NUMLOCK pressed");
      // ... 他のアクション
      break;
    case KEY_NUMLOCK_RELEASED:
      Serial.println("Key KEY_NUMLOCK released");
      // ... 他のアクション
      break;
    // ... 他のキーに対するケース
    case KEY_KP1_PRESSED:
      Serial.println("Key KEY_KP1 pressed");
      Keyboard.press('1');      
      break;
    case KEY_KP1_RELEASED:
      Serial.println("Key KEY_KP1 released");
      Keyboard.release('1');
      break;
    case KEY_KP2_PRESSED:
      Serial.println("Key KEY_KP2 pressed");
      Keyboard.press('2');      
      break;
    case KEY_KP2_RELEASED:
      Serial.println("Key KEY_KP2 released");
      Keyboard.release('2');
      break;
    case KEY_KP3_PRESSED:
      Serial.println("Key KEY_KP3 pressed");
      Keyboard.press('3');      
      break;
    case KEY_KP3_RELEASED:
      Serial.println("Key KEY_KP3 released");
      Keyboard.release('3');
      break;
    case KEY_KP4_PRESSED:
      Serial.println("Key KEY_KP4 pressed");
      Keyboard.press('4');      
      break;
    case KEY_KP4_RELEASED:
      Serial.println("Key KEY_KP4 released");
      Keyboard.release('4');
      break;
    case KEY_KP5_PRESSED:
      Serial.println("Key KEY_KP5 pressed");
      Keyboard.press('5');      
      break;
    case KEY_KP5_RELEASED:
      Serial.println("Key KEY_KP5 released");
      Keyboard.release('5');
      break;
    case KEY_KP6_PRESSED:
      Serial.println("Key KEY_KP6 pressed");
      Keyboard.press('6');      
      break;
    case KEY_KP6_RELEASED:
      Serial.println("Key KEY_KP6 released");
      Keyboard.release('6');
      break;
    case KEY_KP7_PRESSED:
      Serial.println("Key KEY_KP7 pressed");
      Keyboard.press('7');      
      break;
    case KEY_KP7_RELEASED:
      Serial.println("Key KEY_KP7 released");
      Keyboard.release('7');
      break;
    case KEY_KP8_PRESSED:
      Serial.println("Key KEY_KP8 pressed");
      Keyboard.press('8');      
      break;
    case KEY_KP8_RELEASED:
      Serial.println("Key KEY_KP8 released");
      Keyboard.release('8');
      break;
    case KEY_KP9_PRESSED:
      Serial.println("Key KEY_KP9 pressed");
      Keyboard.press('9');      
      break;
    case KEY_KP9_RELEASED:
      Serial.println("Key KEY_KP9 released");
      Keyboard.release('9');
      break;
    case KEY_KP0_PRESSED:
      Serial.println("Key KEY_KP0 pressed");
      Keyboard.press('0');      
      break;
    case KEY_KP0_RELEASED:
      Serial.println("Key KEY_KP0 released");
      Keyboard.release('0');
      break;

    case KEY_KPDOT_PRESSED:
      Serial.println("Key KEY_KPDOT pressed");
      Keyboard.press('.');      
      break;
    case KEY_KPDOT_RELEASED:
      Serial.println("Key KEY_KPDOT released");
      Keyboard.release('.');
      break;

    case KEY_KPENTER_PRESSED:
      Serial.println("Key KEY_KPENTER pressed");
      Keyboard.press('.');      
      break;
    case KEY_KPENTER_RELEASED:
      Serial.println("Key KEY_KPENTER released");
      Keyboard.release('.');
      break;

    case KEY_KPPLUS_PRESSED:
      Serial.println("Key KEY_KPPLUS pressed");
      Keyboard.press('+');      
      break;
    case KEY_KPPLUS_RELEASED:
      Serial.println("Key KEY_KPPLUS released");
      Keyboard.release('+');
      break;

    case KEY_KPMINUS_PRESSED:
      Serial.println("Key KEY_KPMINUS pressed");
      Keyboard.press('-');      
      break;
    case KEY_KPMINUS_RELEASED:
      Serial.println("Key KEY_KPMINUS released");
      Keyboard.release('-');
      break;

    case KEY_BACKSPACE_PRESSED:
      Serial.println("Key KEY_BACKSPACE pressed");
      Keyboard.press(KEY_BACKSPACE);      
      break;
    case KEY_BACKSPACE_RELEASED:
      Serial.println("Key KEY_BACKSPACE released");
      Keyboard.release(KEY_BACKSPACE);
      break;

    case KEY_KPASTERISK_PRESSED:
      Serial.println("Key KEY_KPASTERISK pressed");
      Keyboard.press('*');      
      break;
    case KEY_KPASTERISK_RELEASED:
      Serial.println("Key KEY_KPASTERISK released");
      Keyboard.release('*');
      break;

    case KEY_KPSLASH_PRESSED:
      Serial.println("Key KEY_KPSLASH pressed");
      Keyboard.press('/');      
      break;
    case KEY_KPSLASH_RELEASED:
      Serial.println("Key KEY_KPSLASH released");
      Keyboard.release('/');
      break;

    case KEY_INSERT_PRESSED:
      Serial.println("Key INSERT pressed");
      Keyboard.press(KEY_INSERT);      
      break;
    case KEY_INSERT_RELEASED:
      Serial.println("Key INSERT released");
      Keyboard.release(KEY_INSERT);
      break;

    case KEY_DELETE_PRESSED:
      Serial.println("Key DELETE pressed");
      Keyboard.press(KEY_DELETE);      
      break;
    case KEY_DELETE_RELEASED:
      Serial.println("Key DELETE released");
      Keyboard.release(KEY_DELETE);
      break;

    case KEY_END_PRESSED:
      Serial.println("Key END pressed");
      Keyboard.press(KEY_END);      
      break;
    case KEY_END_RELEASED:
      Serial.println("Key END released");
      Keyboard.release(KEY_END);
      break;

    case KEY_DOWN_PRESSED:
      Serial.println("Key DOWN pressed");
      Keyboard.press(KEY_DOWN_ARROW);      
      break;
    case KEY_DOWN_RELEASED:
      Serial.println("Key DOWN released");
      Keyboard.release(KEY_DOWN_ARROW);
      break;

    case KEY_PAGEDOWN_PRESSED:
      Serial.println("Key END pressed");
      Keyboard.press(KEY_PAGE_DOWN);      
      break;
    case KEY_PAGEDOWN_RELEASED:
      Serial.println("Key END released");
      Keyboard.release(KEY_PAGE_DOWN);
      break;

    case KEY_LEFT_PRESSED:
      Serial.println("Key LEFT pressed");
      Keyboard.press(KEY_LEFT_ARROW);      
      break;
    case KEY_LEFT_RELEASED:
      Serial.println("Key LEFT released");
      Keyboard.release(KEY_LEFT_ARROW);
      break;

    case KEY_RIGHT_PRESSED:
      Serial.println("Key RIGHT pressed");
      Keyboard.press(KEY_RIGHT_ARROW);      
      break;
    case KEY_RIGHT_RELEASED:
      Serial.println("Key RIGHT released");
      Keyboard.release(KEY_RIGHT_ARROW);
      break;

    case KEY_HOME_PRESSED:
      Serial.println("Key HOME pressed");
      Keyboard.press(KEY_HOME);      
      break;
    case KEY_HOME_RELEASED:
      Serial.println("Key HOME released");
      Keyboard.release(KEY_HOME);
      break;

    case KEY_UP_PRESSED:
      Serial.println("Key UP pressed");
      Keyboard.press(KEY_UP_ARROW);      
      break;
    case KEY_UP_RELEASED:
      Serial.println("Key UP released");
      Keyboard.release(KEY_UP_ARROW);
      break;

    case KEY_PAGEUP_PRESSED:
      Serial.println("Key END pressed");
      Keyboard.press(KEY_PAGE_UP);      
      break;
    case KEY_PAGEUP_RELEASED:
      Serial.println("Key END released");
      Keyboard.release(KEY_PAGE_UP);
      break;

    case MOUSE_LEFT_PRESSED:
      Serial.println("Mouse Button ['BTN_LEFT', 'BTN_MOUSE'] pressed");
      Mouse.press(MOUSE_LEFT);
      break;
    case MOUSE_LEFT_RELEASED:
      Serial.println("Mouse Button ['BTN_LEFT', 'BTN_MOUSE'] released");
      Mouse.release(MOUSE_LEFT);
      break;

    case MOUSE_RIGHT_PRESSED:
      Serial.println("Mouse Button BTN_RIGHT pressed");
      Mouse.press(MOUSE_RIGHT);
      break;
    case MOUSE_RIGHT_RELEASED:
      Serial.println("Mouse Button BTN_RIGHT released");
      Mouse.release(MOUSE_RIGHT);
      break;

    case MOUSE_MIDDLE_PRESSED:
      Serial.println("Mouse Button BTN_MIDDLE pressed");
      Mouse.press(MOUSE_MIDDLE);
      break;
    case MOUSE_MIDDLE_RELEASED:
      Serial.println("Mouse Button BTN_MIDDLE released");
      Mouse.release(MOUSE_MIDDLE);
      break;

    case MOUSE_WHEEL_DOWN:
      Serial.println("Mouse wheel scrolled down");
      Mouse.move(0, 0, -1);
      break;
    case MOUSE_WHEEL_UP:
      Serial.println("Mouse wheel scrolled up");
      Mouse.move(0, 0, 1);
      break;

    case MOUSE_MOVE_V:
      Serial.println("Mouse moved vertically: ");
      Mouse.move(0, move_v, 0);
      break;

    case MOUSE_MOVE_H:
      Serial.println("Mouse moved horizontally: ");
      Mouse.move(move_h, 0, 0);
      break;

    default:
      // 未知の入力
      Serial.println("unknown input");
      break;
  }
  
  delay(10);  // 短い遅延
}

int readExternalInput() {
    while (Serial1.available() > 0) {  // シリアルバッファにデータがある場合
        String input = Serial1.readStringUntil('\n');  // 改行までの文字列を読み込む
        input.trim();  // 余分な空白や制御文字を削除
    Serial.println(input);  
    // 他のすべてのキーとマウスイベントをここでチェック        
    if (input == "Key KEY_NUMLOCK pressed") return KEY_NUMLOCK_PRESSED;
    if (input == "Key KEY_NUMLOCK released") return KEY_NUMLOCK_RELEASED;
    if (input == "Key KEY_KP1 pressed") return KEY_KP1_PRESSED;
    if (input == "Key KEY_KP1 released") return KEY_KP1_RELEASED;
    if (input == "Key KEY_KP2 pressed") return KEY_KP2_PRESSED;
    if (input == "Key KEY_KP2 released") return KEY_KP2_RELEASED;
    if (input == "Key KEY_KP3 pressed") return KEY_KP3_PRESSED;
    if (input == "Key KEY_KP3 released") return KEY_KP3_RELEASED;
    if (input == "Key KEY_KP4 pressed") return KEY_KP4_PRESSED;
    if (input == "Key KEY_KP4 released") return KEY_KP4_RELEASED;
    if (input == "Key KEY_KP5 pressed") return KEY_KP5_PRESSED;
    if (input == "Key KEY_KP5 released") return KEY_KP5_RELEASED;
    if (input == "Key KEY_KP6 pressed") return KEY_KP6_PRESSED;
    if (input == "Key KEY_KP6 released") return KEY_KP6_RELEASED;
    if (input == "Key KEY_KP7 pressed") return KEY_KP7_PRESSED;
    if (input == "Key KEY_KP7 released") return KEY_KP7_RELEASED;
    if (input == "Key KEY_KP8 pressed") return KEY_KP8_PRESSED;
    if (input == "Key KEY_KP8 released") return KEY_KP8_RELEASED;
    if (input == "Key KEY_KP9 pressed") return KEY_KP9_PRESSED;
    if (input == "Key KEY_KP9 released") return KEY_KP9_RELEASED;
    if (input == "Key KEY_KP0 pressed") return KEY_KP0_PRESSED;
    if (input == "Key KEY_KP0 released") return KEY_KP0_RELEASED;
    if (input == "Key KEY_KPDOT pressed") return KEY_KPDOT_PRESSED;
    if (input == "Key KEY_KPDOT released") return KEY_KPDOT_RELEASED;
    if (input == "Key KEY_KPENTER pressed") return KEY_KPENTER_PRESSED;
    if (input == "Key KEY_KPENTER released") return KEY_KPENTER_RELEASED;
    if (input == "Key KEY_KPPLUS pressed") return KEY_KPPLUS_PRESSED;
    if (input == "Key KEY_KPPLUS released") return KEY_KPPLUS_RELEASED;
    if (input == "Key KEY_KPMINUS pressed") return KEY_KPMINUS_PRESSED;
    if (input == "Key KEY_KPMINUS released") return KEY_KPMINUS_RELEASED;
    if (input == "Key KEY_BACKSPACE pressed") return KEY_BACKSPACE_PRESSED;
    if (input == "Key KEY_BACKSPACE released") return KEY_BACKSPACE_RELEASED;
    if (input == "Key KEY_KPASTERISK pressed") return KEY_KPASTERISK_PRESSED;
    if (input == "Key KEY_KPASTERISK released") return KEY_KPASTERISK_RELEASED;
    if (input == "Key KEY_KPSLASH pressed") return KEY_KPSLASH_PRESSED;
    if (input == "Key KEY_KPSLASH released") return KEY_KPSLASH_RELEASED;
    if (input == "Key KEY_INSERT pressed") return KEY_INSERT_PRESSED;
    if (input == "Key KEY_INSERT released") return KEY_INSERT_RELEASED;
    if (input == "Key KEY_DELETE pressed") return KEY_DELETE_PRESSED;
    if (input == "Key KEY_DELETE released") return KEY_DELETE_RELEASED;
    if (input == "Key KEY_END pressed") return KEY_END_PRESSED;
    if (input == "Key KEY_END released") return KEY_END_RELEASED;
    if (input == "Key KEY_DOWN pressed") return KEY_DOWN_PRESSED;
    if (input == "Key KEY_DOWN released") return KEY_DOWN_RELEASED;
    if (input == "Key KEY_PAGEDOWN pressed") return KEY_PAGEDOWN_PRESSED;
    if (input == "Key KEY_PAGEDOWN released") return KEY_PAGEDOWN_RELEASED;
    if (input == "Key KEY_LEFT pressed") return KEY_LEFT_PRESSED;
    if (input == "Key KEY_LEFT released") return KEY_LEFT_RELEASED;
    if (input == "Key KEY_RIGHT pressed") return KEY_RIGHT_PRESSED;
    if (input == "Key KEY_RIGHT released") return KEY_RIGHT_RELEASED;
    if (input == "Key KEY_HOME pressed") return KEY_HOME_PRESSED;
    if (input == "Key KEY_HOME released") return KEY_HOME_RELEASED;
    if (input == "Key KEY_UP pressed") return KEY_UP_PRESSED;
    if (input == "Key KEY_UP released") return KEY_UP_RELEASED;
    if (input == "Key KEY_PAGEUP pressed") return KEY_PAGEUP_PRESSED;
    if (input == "Key KEY_PAGEUP released") return KEY_PAGEUP_RELEASED;
    if (input == "Mouse Button ['BTN_LEFT', 'BTN_MOUSE'] pressed") return MOUSE_LEFT_PRESSED;
    if (input == "Mouse Button ['BTN_LEFT', 'BTN_MOUSE'] released") return MOUSE_LEFT_RELEASED;
    if (input == "Mouse Button BTN_RIGHT pressed") return MOUSE_RIGHT_PRESSED;
    if (input == "Mouse Button BTN_RIGHT released") return MOUSE_RIGHT_RELEASED;
    if (input == "Mouse Button BTN_MIDDLE pressed") return MOUSE_MIDDLE_PRESSED;
    if (input == "Mouse Button BTN_MIDDLE released") return MOUSE_MIDDLE_RELEASED;
    if (input == "Mouse wheel scrolled down") return MOUSE_WHEEL_DOWN;
    if (input == "Mouse wheel scrolled up") return MOUSE_WHEEL_UP;

    if (input.startsWith("Mouse moved vertically: ")) {
        move_v = input.substring(23).toInt();  // 仮定: 数値はメッセージの最後にあります
        return MOUSE_MOVE_V;
      }
    if (input.startsWith("Mouse moved horizontally: ")) {
        move_h = input.substring(25).toInt();  // 仮定: 数値はメッセージの最後にあります
        return MOUSE_MOVE_H;
      }
    }
    return -1;  // 未知の入力
}
