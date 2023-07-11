#include <Arduino.h>

#define U9_RED A14
#define U9_GREEN A13
#define U8_RED A16
#define U8_GREEN A17
#define U8_BLUE A15
#define U5_RED A9
#define U5_GREEN A8
#define U5_BLUE A4
#define BUZZ A12


void lightUpLED(int U9, int U5, int U8, int BZ) {
  // Port registers for each port
  volatile uint32_t* portU9 = portOutputRegister(digitalPinToPort(U9_RED));
  volatile uint32_t* portU5 = portOutputRegister(digitalPinToPort(U5_RED));
  volatile uint32_t* portU8 = portOutputRegister(digitalPinToPort(U8_RED));
  volatile uint32_t* portBZ = portOutputRegister(digitalPinToPort(BUZZ));

  // Pin masks for each pin
  uint32_t maskU9_RED = digitalPinToBitMask(U9_RED);
  uint32_t maskU9_GREEN = digitalPinToBitMask(U9_GREEN);
  uint32_t maskU5_RED = digitalPinToBitMask(U5_RED);
  uint32_t maskU5_GREEN = digitalPinToBitMask(U5_GREEN);
  uint32_t maskU5_BLUE = digitalPinToBitMask(U5_BLUE);
  uint32_t maskU8_RED = digitalPinToBitMask(U8_RED);
  uint32_t maskU8_GREEN = digitalPinToBitMask(U8_GREEN);
  uint32_t maskU8_BLUE = digitalPinToBitMask(U8_BLUE);
  uint32_t maskBZ = digitalPinToBitMask(BUZZ);

  // U9
  if (U9 == 0) {
    *portU9 &= ~(maskU9_RED | maskU9_GREEN);
  } else if (U9 == 1) {
    *portU9 = (*portU9 & ~maskU9_GREEN) | maskU9_RED;
  } else if (U9 == 2) {
    *portU9 = (*portU9 & ~maskU9_RED) | maskU9_GREEN;
  }

  // U5
  if (U5 == 0) {
    *portU5 &= ~(maskU5_RED | maskU5_GREEN | maskU5_BLUE);
  } else if (U5 == 1) {
    *portU5 = (*portU5 & ~(maskU5_GREEN | maskU5_BLUE)) | maskU5_RED;
  } else if (U5 == 2) {
    *portU5 = (*portU5 & ~(maskU5_RED | maskU5_BLUE)) | maskU5_GREEN;
  } else if (U5 == 3) {
    *portU5 = (*portU5 & ~(maskU5_RED | maskU5_GREEN)) | maskU5_BLUE;
  }

  // U8
  if (U8 == 0) {
    *portU8 &= ~(maskU8_RED | maskU8_GREEN | maskU8_BLUE);
  } else if (U8 == 1) {
    *portU8 = (*portU8 & ~(maskU8_GREEN | maskU8_BLUE)) | maskU8_RED;
  } else if (U8 == 2) {
    *portU8 = (*portU8 & ~(maskU8_RED | maskU8_BLUE)) | maskU8_GREEN;
  } else if (U8 == 3) {
    *portU8 = (*portU8 & ~(maskU8_RED | maskU8_GREEN)) | maskU8_BLUE;
  }

  // BUZZ
  *portBZ = (BZ == 0) ? (*portBZ & ~maskBZ) : (*portBZ | maskBZ);
}


void setup() {

  pinMode(U9_RED, OUTPUT);
  pinMode(U9_GREEN, OUTPUT);
  pinMode(U8_RED, OUTPUT);
  pinMode(U8_GREEN, OUTPUT);
  pinMode(U8_BLUE, OUTPUT);
  pinMode(U5_RED, OUTPUT);
  pinMode(U5_GREEN, OUTPUT);
  pinMode(U5_BLUE, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  
}

void loop() {

  lightUpLED(2, 2, 2, 0);

}


