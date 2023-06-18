// XBOX Controller Key Assign for X68000 GRADIUS
#include <Keyboard.h>
#include <XBOXONE.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXONE Xbox(&Usb);

static bool r_s = false, r_m = true;
static unsigned long time_s = millis(), time_m = millis();

static bool kp8 = false;
static bool kp2 = false;
static bool kp4 = false;
static bool kp6 = false;
static bool aru = false;
static bool ard = false;
static bool arl = false;
static bool arr = false;
static bool kpe = false;
static bool kesc = false;
static bool kc = false;
static bool kx = false;
static bool kz = false;

void setup() {
  if (Usb.Init() == -1) {
    while (1); //halt
  }
}
void loop() {
  unsigned long time = millis();

  Usb.Task();
  if (Xbox.XboxOneConnected) {
    if (Xbox.getButtonPress(UP) || (Xbox.getAnalogHat(LeftHatY) > 7500)) {
      if (!kp8) {
        Keyboard.press(KEY_KP_8);
        kp8 = true;
      }
    } else {
      if (kp8) {
        Keyboard.release(KEY_KP_8);
        kp8 = false;
      }
    }
    if (Xbox.getButtonPress(DOWN) || (Xbox.getAnalogHat(LeftHatY) < -7500)) {
      if (!kp2) {
        Keyboard.press(KEY_KP_2);
        kp2 = true;
      }
    } else {
      if (kp2) {
        Keyboard.release(KEY_KP_2);
        kp2 = false;
      }
    }
    if (Xbox.getButtonPress(LEFT) || (Xbox.getAnalogHat(LeftHatX) < -7500)) {
      if (!kp4) {
        Keyboard.press(KEY_KP_4);
        kp4 = true;
      }
    } else {
      if (kp4) {
        Keyboard.release(KEY_KP_4);
        kp4 = false;
      }
    }
    if (Xbox.getButtonPress(RIGHT) || (Xbox.getAnalogHat(LeftHatX) > 7500)) {
      if (!kp6) {
        Keyboard.press(KEY_KP_6);
        kp6 = true;
      }
    } else {
      if (kp6) {
        Keyboard.release(KEY_KP_6);
        kp6 = false;
      }
    }

    if (Xbox.getButtonPress(B) || Xbox.getButtonPress(RT) || Xbox.getButtonPress(RB)) {
      if (!r_s) {
        if (!kx) {
          Keyboard.press('x');
          kx = true;
        }
      } else {
        if (time_s < time) {
          if (!kx) {
            Keyboard.press('x');
            kx = true;
          } else {
            Keyboard.release('x');
            kx = false;
          }
          time_s = time + 33;
        }
      }
    } else {
      if (kx) {
        Keyboard.release('x');
        kx = false;
      }
      if (r_s) time_s = time;
    }
    if (Xbox.getButtonPress(A) || Xbox.getButtonPress(LT) || Xbox.getButtonPress(RB)) {
      if (!r_m) {
        if (!kc) {
          Keyboard.press('c');
          kc = true;
        }
      } else {
        if (time_m < time) {
          if (!kc) {
            Keyboard.press('c');
            kc = true;
          } else {
            Keyboard.release('c');
            kc = false;
          }
          time_m = time + 33;
        }
      }
    } else {
      if (kc) {
        Keyboard.release('c');
        kc = false;
      }
      if (r_m) time_m = time;
    }
    if (Xbox.getButtonPress(X)) {
      if (!kz) {
        Keyboard.press('z');
        kz = true;
      }
    } else {
      if (kz) {
        Keyboard.release('z');
        kz = false;
      }
    }

    if (Xbox.getButtonClick(Y)) {
      if (!r_s) {
        time_s = time;
        r_s = true;
      } else {
        r_s = false;
      }
    }

    if (Xbox.getButtonPress(START)) {
      if (!kpe) {
        Keyboard.press(KEY_KP_ENTER);
        kpe = true;
      }
    } else {
      if (kpe) {
        Keyboard.release(KEY_KP_ENTER);
        kpe = false;
      }
    }
    if (Xbox.getButtonPress(BACK)) {
      if (!kesc) {
        Keyboard.press(KEY_ESC);
        kesc = true;
      }
    } else {
      if (kesc) {
        Keyboard.release(KEY_ESC);
        kesc = false;
      }
    }

    if (Xbox.getAnalogHat(RightHatY) > 7500) {
      if (!aru) {
        Keyboard.press(KEY_UP_ARROW);
        aru = true;
      }
    } else {
      if (aru) {
        Keyboard.release(KEY_UP_ARROW);
        aru = false;
      }
    }
    if (Xbox.getAnalogHat(RightHatY) < -7500) {
      if (!ard) {
        Keyboard.press(KEY_DOWN_ARROW);
        ard = true;
      }
    } else {
      if (ard) {
        Keyboard.release(KEY_DOWN_ARROW);
        ard = false;
      }
    }
    if (Xbox.getAnalogHat(RightHatX) < -7500) {
      if (!arl) {
        Keyboard.press(KEY_LEFT_ARROW);
        arl = true;
      }
    } else {
      if (arl) {
        Keyboard.release(KEY_LEFT_ARROW);
        arl = false;
      }
    }
    if (Xbox.getAnalogHat(RightHatX) > 7500) {
      if (!arr) {
        Keyboard.press(KEY_RIGHT_ARROW);
        arr = true;
      }
    } else {
      if (arr) {
        Keyboard.release(KEY_RIGHT_ARROW);
        arr = false;
      }
    }
  }

  delay(1);
}
