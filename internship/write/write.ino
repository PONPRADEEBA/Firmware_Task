#include <EEPROM.h>

void setup() {
  Serial.begin(2400);

 
  char val[] = {"Finance Minister Arun Jaitley Tuesday hit out at fowould be triggered by MSME lending, saying postmortem is easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentary committee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis. Government should focus on sources of the next crisis, not just the last one.In particular, government should refrain from setting ambitious credit targets or waiving loans. Credit targets are sometimes achieved by abandoning appropriate due diligence, creating the environment for future NPAs, Rajan said in the note Both MUDRA loans as well as the Kisan Credit Card, Rajan, who was RBI governor for three years till September 2016, is currently \n"};
  int EEPROM_address = 0;

  EEPROM.put(EEPROM_address, val);

  Serial.println("Data sent to EEPROM successfully");
}

void loop() {
  static unsigned long lTime = 0;
  static unsigned long transmitTime = 0;
  static unsigned long totalBits = 0;
  static unsigned long lCount = 0;

  unsigned long cTime = millis();
  unsigned long timerequired = cTime - lTime;

  if (timerequired >= 5000) { 
    float averageSpeed = (float)totalBits / transmitTime * 1000 / lCount; 

    Serial.print("Average Speed: ");
    Serial.print(averageSpeed);
    Serial.println(" bps");

    lTime = cTime;
    transmitTime = 0;
    totalBits = 0;
    lCount = 0;
  }

  
  unsigned long sTime = millis();
  char val[128]; 
  EEPROM.get(0, val);
  unsigned long eTime = millis();

  transmitTime += eTime - sTime;
  totalBits += 8 * sizeof(val); 
  lCount++;
}


