int LED = 3;
int PWM = 0;
  
void setup() { 
    pinMode(LED, OUTPUT);

    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    
}
 
void loop() {
    for(PWM = 0; PWM < 256; PWM++) {
      analogWrite(LED, PWM); 
      delay(10); 
    }
}
