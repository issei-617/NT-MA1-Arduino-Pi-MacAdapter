# NT-MA1-Arduino-Pi-MacAdapter
Enable both the mouse and ten-key functions of NT-MA1 (numeric keypad mouse, sanwasupply) for use on a Mac.

# test


## 背景
　NT-MA1（テンキーマウス）はテンキーとマウスが一体になったusb接続のHID（Human Interface Device）である。残念ながらMacでは、NT-MA1のマウス機能は使えるが、テンキー機能は使えない。そこで、マウス機能もテンキー機能も使えるようにしたい。ChatGPTに聞きながら実現できた。

## 注意
　実用を目的としたものではなく、あくまでやってみた。
"The intention behind this was not for practical use, but rather just to give it a try."

## 方針
　ubuntuをデュアルブートでインストールしたMacにNT-MA1を接続すると、ubuntuではマウス機能もテンキー機能も使えた。一方、MacOSの方では、マウス機能のみ使えた。このことから、ハードウェアの問題ではなく、ソフトウェア（デバイスドライバ）の問題と推測された。

　では、MacOS用のデバイスドライバを書けるかというと、私には難しすぎて、断念した。

　次に、HID機能を有するマイクロコントローラー（例:Arduino Leonardo）にusb host shieldを装着し、usb hostshieldでNT-MA1の情報を受け取り、Arduino Leonardoを介してPCへHIDとしてのデータを送ることを考えた。この場合、usb hostshieldでデータを受け取る際のライブラリを自分で書く必要があり、そのためにはNT-MA1とPC間のusb通信を解析する必要がある。私には難しすぎて、断念した。

　Raspberry pi 3B+ にNT-MA1を接続すると、マウス機能もテンキー機能も使える。そこでRaspberrypiとArduinoとを併用する方法を採用した。RaspberryipでNT-MA1のデータを受けとり、それをシリアル通信でArduinoへ送り、そのデータに基づきArduino内でキーエミュレーションする。

## 準備
　raspberrypiではGUI（Graphical User Interface）は不要。そこで、raspberrypiにインストールするOSは、CLI（Command Line Interface）であるRaspberrypi os liteにした。

　ArduinoとRaspberrypiとのシリアル通信の方法としてI2CやUARTがある。簡単な方法としてUARTを採用した。


### 実体配線図、回路図

## Raspberrypi側のコード

### raspberrypiでテンキーマウスの情報を取得する方法
`evtest` や `/dev/input/theInterface`を直接読む方法が考えられた。Raspberrypi側はPythonで書くので、Pythonのキー入力を受け取るライブラリである`evdev`を用いることにした。

## NT-MA1のproduct IDとventer IDを調べておく。
evdevでデバイスからの入力を読み取るときに、どのデバイスから読み取るかを指定する必要がある。product IDとvender IDとでデバイスを特定できる。適当なツールを用いてproduct IDとventer IDを調べておく。なお、NT-MA1はVENDOR_ID = 0x05c7、PRODUCT_ID = 0x6004であった。

## 複数デバイスからデータを受け取る
`evdev`上では、NT-MA1のテンキーからの入力とマウスからの入力は別のデバイスとして扱われる。したがって、複数デバイスからの入力を待ち受けるプログラムを書くことになる。これには`select`を用いることにした。

## マウスからのデータを監視し続ける方法。
ChatGPTからは（1）polling（ループして繰り返し読み取る）、（2）マルチスレッド、（3）マルチプロセスを用いた方法の提案があり、いずれも実現可能であった。最も単純なpollingを用いることにした。

## オートリピートの実現
以下のようにして実現した。Pythonの`time`モジュールを使用して現在の時刻を取得し、キーが押されてからの経過時間を測定する。一定の閾値を超えたらオートリピートをトリガーとして、そのキーコードを表示する。

## Arduino側
uartを通じて送られてきたデータに基づき、キーをエミュレーションするコードを書く。


## 使い方

（1）上記のように配線する。
（2）　、、、をArduinoIDEからマイコンボードに書き込んでおく。
（3）Raspberrypiで、、、を実行する。するとNT-MA1からの入力の監視が始まる。（Raspberrypiへ母艦のPCからssh接続し、そこから、、、を実行すると楽である）。
（4）ArduinoIDEのシリアルモニタを開く。コード上に書いてある通り、通信速度は19200。すると、シリアルモニタ上にuartから受信したデータを表示するとともに、Mac上に文字が入力されたり、マウスポインタが移動したりする。

### 注意
マウスの動きはかなり鈍く、実用性に乏しい。

　



