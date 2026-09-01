# iotsaOLEDServer - web server to drive an SSD1306 OLED display

![build-platformio](https://github.com/cwi-dis/iotsaOLEDServer/workflows/build-platformio/badge.svg)
![build-arduino](https://github.com/cwi-dis/iotsaOLEDServer/workflows/build-arduino/badge.svg)

iotsaOLEDServer is a web server that drives an SSD1306 OLED display. An attempt has been made to keep
it as compatible as possible with [iotsaDisplayServer](https://github.com/cwi-dis/iotsaDisplayServer),
which drives a character LCD instead.

Home page is <https://github.com/cwi-dis/iotsaOLEDServer>.
This software is licensed under the [MIT license](LICENSE.txt) by the   CWI DIS group, <http://www.dis.cwi.nl>.

## Software requirements

* PlatformIO (recommended). `pio run` builds every environment in `platformio.ini`; the Adafruit GFX and SSD1306 libraries are pulled in automatically.
* Or the Arduino IDE, with the iotsa framework from <https://github.com/cwi-dis/iotsa> and the Adafruit GFX / Adafruit SSD1306 libraries.

## Hardware requirements

* a Wemos LOLIN32 board with an onboard SSD1306 OLED (the `lolin32-oled` environment). An ESP8266 with a separate SSD1306 module also builds (the `nodemcuv2` environment).

## Operation

The first time the board boots it creates a Wifi network with a name similar to _config-iotsa1234_.  Connect a device to that network and visit <http://192.168.4.1>. Configure your device name (using the name _oled_ is suggested), WiFi name and password, and after reboot the iotsa board should connect to your network and be visible as <http://oled.local>.

Visit <http://oled.local/display> to show a message on the display.

There is a command-line tool (for Linux or MacOSX) in repository <https://github.com/cwi-dis/iotsaDisplayServer> file `extras/lcdecho` that allows you to show messages and control the other parameters programmatically, use

```
lcdecho --help
```

for help.