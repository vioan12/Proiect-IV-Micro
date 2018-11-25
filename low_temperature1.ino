#include <LiquidCrystal.h>
const int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2, TEMP = 0, LED = 13, BUZZER = 8, NOTE_C7 = 2093;
float minTemperature,lastTemperature;
int sum,count;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
void setup()
{
  lcd.begin(16, 2);
  sum=0;
  count=0;
  minTemperature=1000;
  lastTemperature=1000;
}

void loop()
{
  if(count<5){
    delay(650);
    sum+=analogRead(TEMP);
    count++;
  }else{
	lastTemperature=sum/5;
    lastTemperature=lastTemperature*5.0/1024;
    lastTemperature=(lastTemperature-0.5)*100;
    lcd.print(lastTemperature);
    if(lastTemperature<minTemperature){
      minTemperature=lastTemperature;
    }
    String lastTemperatureString, minTemperatureString;
    lastTemperatureString = String(lastTemperature, 2);
    minTemperatureString = String(minTemperature, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("temp:" + lastTemperatureString + "oC");
    lcd.setCursor(0, 1);
    lcd.print(" min:" + minTemperatureString + "oC");
    if(lastTemperature>10){
      digitalWrite(LED,HIGH);
	}
    count=0;
    sum=0;
  }
} 