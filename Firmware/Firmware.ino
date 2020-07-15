#include <RGBLed.h>

#include <RGBLED.h>

#define RED  3
#define GREEN 6
#define BLUE 5

#define HUE  A0
#define SAT A1
#define BRIGHT A2

RGBLED LED_Strip(RED, GREEN, BLUE, COMMON_CATHODE);

int PWM = 0;






typedef enum {
  Red = 1 ,
  Orange_Red ,
  Orange ,
  Coral ,
  Yellow ,
  Green ,
  Lime ,
  Cyan ,
  Baby_Blue ,
  Cerulean ,
  Blue ,
  Azure ,
  Blue_Violet ,
  Byzantium ,
  Pink ,
  White,
  OFF
} Colors_List;

int HSV[17][3];

Colors_List Selected_Color = Red;
int Last_Color = Selected_Color;
void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(HUE, INPUT);
  pinMode(SAT, INPUT);
  pinMode(BRIGHT, INPUT);

  Serial.begin(9600);
  while (!Serial) {
    ;
  }


}

void Get_HSV_From_ADC() {
  int h = 0;
  int s = 0;
  int v = 0;
  int i = 0;
  int n = 30;
  int y = 1;
  int m = 3;//16

  do {

    for (i = 0; i < n; i++) {
      h += analogRead(HUE);
      delay(1);
    }
    h /= n;

    for (i = 0; i < n; i++) {
      s += analogRead(SAT);
      delay(1);
    }
    s /= n;

    for (i = 0; i < n; i++) {
      v += analogRead(BRIGHT);
      delay(1);
    }
    v /= n;

    h = map(h, 0, 1030, 0, 359);
    s = map(s, 0, 1023, 0, 100);
    v = map(v, 0, 1023, 0, 100);

    Serial.print(h);
    Serial.print(',');
    Serial.print(s);
    Serial.print(',');
    Serial.println(v);

    LED_Strip.writeHSV(h, s, v);



    if (Serial.available() > 0) {
      int c = Serial.parseInt();
      if (c == 1) {
        Serial.println("========================");
        Serial.println("========================");
        Serial.println("========================");
        HSV[y][0] = h;
        HSV[y][1] = s;
        HSV[y][2] = v;

        y++;
      }



    }
  } while (y <= m);

  Serial.println("========================");
  for (i = 0; i <= m; i++) {
    Serial.print(HSV[y][0]);
    Serial.print(',');
    Serial.print(HSV[y][1]);
    Serial.print(',');
    Serial.println(HSV[y][2]);
  }
}


void loop() {
  Get_HSV_From_ADC();


  /*
    if (Serial.available() > 0) {
      int color = Serial.parseInt();
      Selected_Color = color;
      
      Serial.println(Selected_Color);
    }

    
    if (Last_Color != Selected_Color) {
      switch (Selected_Color) {
        case Red:          
          LED_Strip.writeHSV(0, 100, 50);
          break;

        case Orange_Red:          
          LED_Strip.writeHSV(16, 100, 50);
          break;

        case Orange:          
          LED_Strip.writeHSV(24, 100, 50);
          break;

        case Coral:          
          LED_Strip.writeRGB(16, 69, 66);
          break;

        case Yellow:
          LED_Strip.writeHSV(60, 100, 50);          
          break;

        case Green:
          LED_Strip.writeHSV(120, 100 / 100, 25 / 100);          
          break;

        case Lime:
          LED_Strip.writeHSV(75, 100 / 100, 50 / 100);          
          break;

        case Cyan:
          LED_Strip.writeHSV(180, 100 / 100, 50 / 100);          
          break;

        case Baby_Blue:
          LED_Strip.writeHSV(199, 43 / 100, 74 / 100);          
          break;

        case Cerulean:
          LED_Strip.writeHSV(196, 100 / 100, 33 / 100);          
          break;

        case Blue:
          LED_Strip.writeHSV(240, 100 / 100, 50 / 100);          
          break;

        case Azure:
          LED_Strip.writeHSV(210, 100 / 100, 50 / 100);          
          break;

        case Blue_Violet:
          LED_Strip.writeHSV(271, 81 / 100, 53 / 100);          
          break;

        case Byzantium:
          LED_Strip.writeHSV(311, 63 / 100, 30 / 100);          
          break;

        case Pink:
          LED_Strip.writeHSV(339, 57 / 100, 71 / 100);          
          break;

        case White:
          LED_Strip.writeHSV(0, 100 / 100, 100 / 100);          
          break;

        case OFF:
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
          break;
      }
      Last_Color = Selected_Color;
    }

*/
  
}
