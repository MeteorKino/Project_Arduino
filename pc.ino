#include <LiquidCrystal.h>

float R1 = 8100.0; 
float R2 = 995.0; 
float vout = 0.0;
float Voltage_Value = 0, Current_Value = 0;
int Read_Voltage  = A3;
int Read_Current  = A4;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  lcd.print(" Arduino Wattmeter"); 
  lcd.setCursor(0, 1);
  lcd.print("  With Arduino  ");
  delay(2000);
  lcd.clear();
}

void loop() {
 float value = analogRead(Read_Voltage);
 float Current_Value = analogRead(Read_Current);
 
 vout = (value * 5.0) / 1024.0; // see text
 Voltage_Value = vout / (R2/(R1+R2)); 
 Current_Value = Current_Value * (5.0/1023.0) * 0.239;
 float Power_Value = Voltage_Value * Current_Value;
 lcd.setCursor(0, 0);
 lcd.print("V="); lcd.print(Voltage_Value); 
 lcd.print("  "); 
 lcd.print("I=");lcd.print(Current_Value); 
 lcd.setCursor(0, 1);
 lcd.print("Power="); lcd.print(Power_Value); 
 delay(200);
}
