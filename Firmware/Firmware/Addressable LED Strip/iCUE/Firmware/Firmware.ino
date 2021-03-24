#include <CorsairLightingProtocol.h>
#include <FastLED.h>


#define DATA_PIN_CHANNEL_1 6
#define DATA_PIN_CHANNEL_2 3


// Hint: The ATmega32U4 does not have enough memory! MAX 256 at CH1 and 256 at another one (512 max)
#define N_LED_CH1 256
#define N_LED_CH2 256

CRGB ledsChannel1[N_LED_CH1];
CRGB ledsChannel2[N_LED_CH2];


CorsairLightingFirmware firmware = corsairLS100Firmware();
FastLEDController ledController(true);
CorsairLightingProtocolController cLP(&ledController, &firmware);
CorsairLightingProtocolHID cHID(&cLP);


void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN_CHANNEL_1, GRB>(ledsChannel1, N_LED_CH1);
  FastLED.addLeds<WS2812B, DATA_PIN_CHANNEL_2, GRB>(ledsChannel2, N_LED_CH2);
  
  ledController.addLEDs(1, ledsChannel1, N_LED_CH1);
  ledController.addLEDs(0, ledsChannel2, N_LED_CH2);  
}

void loop() {
 
	cHID.update();
  
	if (ledController.updateLEDs()) {
		FastLED.show();
	} 
}
