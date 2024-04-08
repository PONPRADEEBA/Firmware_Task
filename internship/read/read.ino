#include <EEPROM.h>

void setup() {
  Serial.begin(2400);
  
  unsigned long sTime = micros();

  for (int i = 0; i < EEPROM.length(); ++i) {
    char Read = EEPROM.read(i); 
     if (Read == '\0')
      break;
    Serial.write(Read);
  }

  unsigned long eTime = micros(); 


  unsigned long Size = EEPROM.length();
  unsigned long actualtime = eTime - sTime;
  float speed = (float)(8 * Size) / actualtime * 1000000; 

  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.println(" bps");
}

void loop() {
  
}

