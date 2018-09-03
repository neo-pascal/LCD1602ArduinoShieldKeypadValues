//LANGUAGE               Arduino C++
//GITHUB                 https://github.com/neo-pascal
//WRITTEN BY             Neo Ayestaran
//DATE                   30/08/18             
//FILE SAVED AS          LCD1602ArduinoShieldKeypadValues.ino
//FOR Arduino UNO        With 1602 LCD Shield with Keypad
//SOFTWARE FUNCTION      'Display the corresponding decimal kepad 
//                       ADC values to allow for recalibration of 
//                       the define list in DFR_LCD_Keypad.h (lines 38-49).'

#include <LiquidCrystal.h>
#include <DFR_LCD_Keypad.h>

// this is factory config shield initialisation
LiquidCrystal lcd(8,9,4,5,6,7); 

// initialise the keypad
DFR_LCD_Keypad keypad(A0, &lcd);

int last_key, key;

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  
  last_key = keypad.get_last_key();
  key      = keypad.read_key_value();
      
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(key);
  
  delay(10); // optional, but recommended if you are not debouncing the keys
}


