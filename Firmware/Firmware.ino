#include "IRremote.h"
#include <RGBLed.h>
#include <EEPROM.h>

#define LED_RED_PIN     5
#define LED_GREEN_PIN   9
#define LED_BLUE_PIN    10
#define IR_SENSOR_PIN   7

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

IRrecv irrecv(7);
decode_results results;


RGBLed LED_Strip(LED_RED_PIN, LED_GREEN_PIN, LED_BLUE_PIN, COMMON_CATHODE);


int Brightness_Value = 100;



long EEPROM_Last_Color_Addr = 0;
int EEPROM_Last_Brightness_Addr = 4;

long Last_RGB_Color;
int Last_Brightness_Value;


void setup()
{
  Serial.begin(9600);
  /*
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  */
  irrecv.enableIRIn();

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(IR_SENSOR_PIN, INPUT);

  

   

Restore_Last_Adjustments();

}

void loop()
{
  readIR();
  
}

void Restore_Last_Adjustments(){
     
   EEPROM.get(EEPROM_Last_Color_Addr, Last_RGB_Color);
   EEPROM.get(EEPROM_Last_Brightness_Addr, Last_Brightness_Value);
   Run_IR_Command(Last_RGB_Color);
   LED_Strip.brightness(Last_Brightness_Value);
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

void Run_IR_Command(long Code_Received) {

  bool Color_Adjustment = false;

  switch (Code_Received) {

    case SWITCH_ON:
      Serial.println("SWITCH_ON");
      
      LED_Strip.brightness(Brightness_Value);
      
      break;

    case SWITCH_OFF:
      Serial.println("SWITCH_OFF");
      digitalWrite(LED_RED_PIN, LOW);
      digitalWrite(LED_GREEN_PIN, LOW);
      digitalWrite(LED_BLUE_PIN, LOW);

      break;

    case BRIGHTNESS_INCREASE:
      Serial.println("BRIGHTNESS_INCREASE");
      if(Brightness_Value < 100)
        Brightness_Value += 20;
      LED_Strip.brightness(Brightness_Value);
      EEPROM.put(EEPROM_Last_Brightness_Addr, Brightness_Value);
      break;

    case BRIGHTNESS_DECREASE:
      Serial.println("BRIGHTNESS_DECREASE");
      if(Brightness_Value > 20)
        Brightness_Value -= 20;
      LED_Strip.brightness(Brightness_Value);
      EEPROM.put(EEPROM_Last_Brightness_Addr, Brightness_Value);
      break;

    case COLOR_RED:
      Serial.println("COLOR_RED");
      LED_Strip.setColor(RGBLed::RED);
      Color_Adjustment = true;
      break;

    case COLOR_ORANGE_RED:
      Serial.println("COLOR_ORANGE_RED");
      LED_Strip.setColor(RGBLed::ORANGE_RED);
      Color_Adjustment = true;
      break;

    case COLOR_ORANGE:
      Serial.println("COLOR_ORANGE");
      LED_Strip.setColor(RGBLed::ORANGE);
      Color_Adjustment = true;
      break;

    case COLOR_CORAL:
      Serial.println("COLOR_CORAL");
      LED_Strip.setColor(RGBLed::CORAL);
      Color_Adjustment = true;
      break;

    case COLOR_YELLOW:
      Serial.println("COLOR_YELLOW");
      LED_Strip.setColor(RGBLed::YELLOW);
      Color_Adjustment = true;
      break;

    case COLOR_GREEN:
      Serial.println("COLOR_GREEN");
      LED_Strip.setColor(RGBLed::GREEN);
      Color_Adjustment = true;     
      break;

    case COLOR_LIME:
      Serial.println("COLOR_LIME");
      LED_Strip.setColor(RGBLed::LIME);
      Color_Adjustment = true;
      break;

    case COLOR_CYAN:
      Serial.println("COLOR_CYAN");
      LED_Strip.setColor(RGBLed::CYAN);
      Color_Adjustment = true;
      break;

    case COLOR_BABY_BLUE:
      Serial.println("COLOR_BABY_BLUE");
      LED_Strip.setColor(RGBLed::BABY_BLUE);
      Color_Adjustment = true;
      break;

    case COLOR_CERULEAN:
      Serial.println("COLOR_CERULEAN");
      LED_Strip.setColor(RGBLed::CERULEAN);
      Color_Adjustment = true;
      break;

    case COLOR_BLUE:
      Serial.println("COLOR_BLUE");
      LED_Strip.setColor(RGBLed::BLUE);
      Color_Adjustment = true;
      break;

    case COLOR_AZURE:
      Serial.println("COLOR_AZURE");
      LED_Strip.setColor(RGBLed::AZURE);
      Color_Adjustment = true;
      break;

    case COLOR_BLUE_VIOLET:
      Serial.println("COLOR_BLUE_VIOLET");
      LED_Strip.setColor(RGBLed::BLUE_VIOLET);
      Color_Adjustment = true;
      break;

    case COLOR_BYZANTIUM:
      Serial.println("COLOR_BYZANTIUM");
      LED_Strip.setColor(RGBLed::BYZANTIUM);
      Color_Adjustment = true;
      break;

    case COLOR_PINK:
      Serial.println("COLOR_PINK");
      LED_Strip.setColor(RGBLed::PINK);
      Color_Adjustment = true;
      break;

    case COLOR_WHITE:
      Serial.println("COLOR_WHITE");
      LED_Strip.setColor(RGBLed::WHITE);
      Color_Adjustment = true;
      break;

    case EFFECT_FLASH:
      Serial.println("EFFECT_FLASH");
      break;

    case EFFECT_STROBE:
      Serial.println("EFFECT_STROBE");
      break;

    case EFFECT_FADE:
      Serial.println("EFFECT_FADE");
      break;

    case EFFECT_SMOOTH:
      Serial.println("EFFECT_SMOOTH");
      break;
  }
  
  if(Color_Adjustment == true)
    EEPROM.put(EEPROM_Last_Color_Addr, Code_Received);
}
