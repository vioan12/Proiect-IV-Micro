#include <LiquidCrystal.h>
const int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2, TEMP = 0, LED = 13, BUZZER = 8, NOTE_C7 = 2093;
float minTemperature = 1000;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
void setup()
{
  lcd.begin(16, 2);
}

void loop()
{

  int sum=0;
  float temperature;

  for(int i=0;i<5;i++){
    sum+=analogRead(TEMP);
    delay(650);
  }

  temperature=sum/5;
  temperature=temperature*5.0/1024;
  temperature=(temperature-0.5)*100;
  lcd.print(temperature);
  if(temperature<minTemperature){
    minTemperature=temperature;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  lcd.print(minTemperature);
  if(temperature>10){
    digitalWrite(LED,HIGH);
  }
  if(temperature<=10){
    digitalWrite(LED,LOW);
    if(temperature<10){
      tone(BUZZER,NOTE_C7,650);
      delay(120);
      noTone(BUZZER);

  	}
  }  
} 