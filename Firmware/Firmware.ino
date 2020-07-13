int RED = 5;
int BLUE = 3;
int GREEN = 6;

int PWM = 0;
  
void setup() { 
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    digitalWrite(RED, HIGH);
    delay(500);
    digitalWrite(RED, LOW);
    delay(500);
    
    digitalWrite(GREEN, HIGH);
    delay(500);
    digitalWrite(GREEN, LOW);
    delay(500);
       
    digitalWrite(BLUE, HIGH);
    delay(500);
    digitalWrite(BLUE, LOW);
    delay(500);
    
}
 
void loop() {
        digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    for(PWM = 0; PWM < 256; PWM++) {
      analogWrite(RED, PWM); 
      delay(10); 
    }
    
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
        for(PWM = 0; PWM < 256; PWM++) {
      analogWrite(GREEN, PWM); 
      delay(10); 
    }
    
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
        for(PWM = 0; PWM < 256; PWM++) {
      analogWrite(BLUE, PWM); 
      delay(10); 
    }
}
