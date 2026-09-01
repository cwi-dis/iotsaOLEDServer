//
// iotsaOLEDServer: drive an SSD1306 128x64 I2C OLED display over the network.
// Messages, cursor position and an auto-clear timeout are controlled through a
// small REST-like interface (/api/display) or the /display web form. Kept as
// API-compatible as possible with iotsaDisplayServer (which drives a character
// LCD instead). An optional BLE "message" characteristic is compiled in with
// -DIOTSA_WITH_BLE.
//
// (c) 2019 Jack Jansen, Centrum Wiskunde & Informatica. MIT license, see LICENSE.txt.
//

#include <Esp.h>
#include "iotsa.h"
#include "iotsaWifi.h"
#include "iotsaOta.h"

IotsaApplication application("OLED Display Server");

// Configure modules we need
IotsaWifiMod wifiMod(application);  // wifi is always needed
IotsaOtaMod otaMod(application);    // OTA firmware updates

#include "iotsaBLEServer.h"
#ifdef IOTSA_WITH_BLE
IotsaBLEServerMod bleserverMod(application);
#endif

//
// OLED section.
//
#include "iotsaOLED.h"
#define PIN_SDA 5
#define PIN_SCL 4
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

IotsaOLEDMod displayMod(application, PIN_SDA, PIN_SCL, OLED_WIDTH, OLED_HEIGHT);

void setup(void) {
  application.setup();
  application.lateSetup();
#ifndef ESP32
  ESP.wdtEnable(WDTO_120MS);
#endif
}

void loop(void) {
  application.loop();
}
