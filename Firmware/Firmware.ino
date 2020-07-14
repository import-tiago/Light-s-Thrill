#include <RGBLED.h>

#define RED  5
#define GREEN 6
#define BLUE 3

RGBLED LED_Strip(RED, GREEN, BLUE, COMMON_CATHODE);

int PWM = 0;

void setup() {

}

void loop() {

  for (PWM = 0; PWM < 256; PWM++) {
    LED_Strip.writeRGB(PWM, 0, 0);
    delay(10);
  }

  for (PWM = 0; PWM < 256; PWM++) {
    LED_Strip.writeRGB(0, PWM, 0);
    delay(10);
  }

  for (PWM = 0; PWM < 256; PWM++) {
    LED_Strip.writeRGB(0, 0, PWM);
    delay(10);
  }

}
