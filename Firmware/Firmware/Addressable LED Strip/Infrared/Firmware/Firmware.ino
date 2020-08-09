#include <CorsairLightingProtocol.h>
#include <FastLED.h>
#include "IRremote.h"
#include <RGBLed.h>
#include <EEPROM.h>


#define IR_SENSOR_PIN   7
#define SUPPLY_MONITOR_PIN 8

#define DATA_PIN_CHANNEL_1 6
#define DATA_PIN_CHANNEL_2 3

#define BRIGHTNESS_INCREASE   ((long)0xF700FF)
#define COLOR_RED             ((long)0xF720DF)
#define COLOR_ORANGE_RED      ((long)0xF710EF)
#define COLOR_ORANGE          ((long)0xF730CF)
#define COLOR_CORAL           ((long)0xF708F7)
#define COLOR_YELLOW          ((long)0xF728D7)
#define BRIGHTNESS_DECREASE   ((long)0xF7807F)
#define COLOR_GREEN           ((long)0xF7A05F)
#define COLOR_LIME            ((long)0xF7906F)
#define COLOR_CYAN            ((long)0xF7B04F)
#define COLOR_BABY_BLUE       ((long)0xF78877)
#define COLOR_CERULEAN        ((long)0xF7A857)
#define SWITCH_OFF            ((long)0xF740BF)
#define COLOR_BLUE            ((long)0xF7609F)
#define COLOR_AZURE           ((long)0xF750AF)
#define COLOR_BLUE_VIOLET     ((long)0xF7708F)
#define COLOR_BYZANTIUM       ((long)0xF748B7)
#define COLOR_PINK            ((long)0xF76897)
#define SWITCH_ON             ((long)0xF7C03F)
#define COLOR_WHITE           ((long)0xF7E01F)
#define EFFECT_FLASH          ((long)0xF7D02F)
#define EFFECT_STROBE         ((long)0xF7F00F)
#define EFFECT_FADE           ((long)0xF7C837)
#define EFFECT_SMOOTH         ((long)0xF7E817)

#define CONTROLLED_BY_INFRARED  0
#define CONTROLLED_BY_USB       1
bool Current_Control_Device = CONTROLLED_BY_USB;

IRrecv irrecv(7);
decode_results results;

//No Addresable LEDs
//RGBLed LED_Strip(LED_RED_PIN, LED_GREEN_PIN, LED_BLUE_PIN, COMMON_CATHODE);

//Addresable LEDs
// Hint: The ATmega32U4 does not have enough memory for 135 leds on both channels

#define NUM_LEDS1 135
#define NUM_LEDS2 54
CRGB ledsChannel1[135];
CRGB ledsChannel2[54];


int Brightness_Value = 100;



long EEPROM_Last_Color_Addr = 0;
int EEPROM_Last_Brightness_Addr = 4;

long Last_RGB_Color;
int Last_Brightness_Value;



CorsairLightingFirmware firmware = corsairLS100Firmware();
FastLEDController ledController(true);
CorsairLightingProtocolController cLP(&ledController, &firmware);
CorsairLightingProtocolHID cHID(&cLP);

//CRGB ledsChannel1[1];


void setup() {

  Serial.begin(9600);

  irrecv.enableIRIn();

  pinMode(IR_SENSOR_PIN, INPUT);

  FastLED.addLeds<WS2812B, DATA_PIN_CHANNEL_1, GRB>(ledsChannel1, 135);
  FastLED.addLeds<WS2812B, DATA_PIN_CHANNEL_2, GRB>(ledsChannel2, 54);

  ledController.addLEDs(1, ledsChannel1, 135);
  ledController.addLEDs(0, ledsChannel2, 54);

   Restore_Last_Adjustments();

  Current_Control_Device = CONTROLLED_BY_USB;
}

void loop() {
  /*
  if (Current_Control_Device == CONTROLLED_BY_USB) {
    cHID.update();
    if (ledController.updateLEDs()) {
      FastLED.show();
    }
  }
  */
  readIR();
}

void readIR() {
  if (irrecv.decode( &results )) {
    unsigned long IRval = results.value;
    if (IRval == 0xFFFFFFFF) { // 0xFFFFFFFF is the "repeat code" sent when a button is held down
      irrecv.resume();
      return;
    }
    //Serial.println( results.value, HEX);
    Run_IR_Command(results.value);
    irrecv.resume();
  }
}

void setColor(CRGB::HTMLColorCode _color) {

  for (int i = 0; i < NUM_LEDS1; i++) {
    ledsChannel1[i] = _color;
  }
  for (int i = 0; i < NUM_LEDS2; i++) {
    ledsChannel2[i] = _color;
  }
  FastLED.show();
}


void Run_IR_Command(long Code_Received) {

  bool Color_Adjustment = false;

  switch (Code_Received) {

    case SWITCH_ON:
      Serial.println("SWITCH_ON");
      
      FastLED.setBrightness(Brightness_Value);
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case SWITCH_OFF:
      Serial.println("SWITCH_OFF");
      setColor(CRGB::Black);
      Current_Control_Device = CONTROLLED_BY_USB;
      break;

    case BRIGHTNESS_INCREASE:
      Serial.println("BRIGHTNESS_INCREASE");
      if (Brightness_Value <= 255)
        Brightness_Value += 20;
      FastLED.setBrightness(Brightness_Value);
      EEPROM.put(EEPROM_Last_Brightness_Addr, Brightness_Value);
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case BRIGHTNESS_DECREASE:
      Serial.println("BRIGHTNESS_DECREASE");
      if (Brightness_Value > 0)
        Brightness_Value -= 20;
      FastLED.setBrightness(Brightness_Value);
      EEPROM.put(EEPROM_Last_Brightness_Addr, Brightness_Value);
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_RED:
      Serial.println("COLOR_RED");
      setColor(CRGB::Red);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;
  

    case COLOR_ORANGE_RED:
      Serial.println("COLOR_ORANGE_RED");
      setColor(CRGB::OrangeRed);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_ORANGE:
      Serial.println("COLOR_ORANGE");
      setColor(CRGB::Orange);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_CORAL:
      Serial.println("COLOR_CORAL");
      setColor(CRGB::Coral);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_YELLOW:
      Serial.println("COLOR_YELLOW");
      setColor(CRGB::Yellow);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_GREEN:
      Serial.println("COLOR_GREEN");
      setColor(CRGB::Green);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_LIME:
      Serial.println("COLOR_LIME");
      setColor(CRGB::LawnGreen);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_CYAN:
      Serial.println("COLOR_CYAN");
      setColor(CRGB::Aqua);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_BABY_BLUE:
      Serial.println("COLOR_BABY_BLUE");
      setColor(CRGB::DeepSkyBlue);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_CERULEAN:
      Serial.println("COLOR_CERULEAN");
      setColor(CRGB::DodgerBlue);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_BLUE:
      Serial.println("COLOR_BLUE");
      setColor(CRGB::Blue);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_AZURE:
      Serial.println("COLOR_AZURE");
      setColor(CRGB::DarkBlue);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_BLUE_VIOLET:
      Serial.println("COLOR_BLUE_VIOLET");
      setColor(CRGB::BlueViolet);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_BYZANTIUM:
      Serial.println("COLOR_BYZANTIUM");
      setColor(CRGB::Purple);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_PINK:
      Serial.println("COLOR_PINK");
      setColor(CRGB::Crimson);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;

    case COLOR_WHITE:
      Serial.println("COLOR_WHITE");
      setColor(CRGB::White);
      Color_Adjustment = true;
      Current_Control_Device = CONTROLLED_BY_INFRARED;
      break;
  }
   if (Color_Adjustment == true)
   EEPROM.put(EEPROM_Last_Color_Addr, Code_Received);
}

void Restore_Last_Adjustments() {

  EEPROM.get(EEPROM_Last_Color_Addr, Last_RGB_Color);
  //EEPROM.get(EEPROM_Last_Brightness_Addr, Last_Brightness_Value);
  Run_IR_Command(Last_RGB_Color);
  //LED_Strip.brightness(Last_Brightness_Value);
}
