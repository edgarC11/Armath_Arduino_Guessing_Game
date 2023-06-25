#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int ROWS = 4; //four rows
const int COLS = 4; //three columns

byte lcd_col = 0;
byte lcd_row = 1;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROWS] = {22, 24, 26, 28}; 
byte pin_cols[COLS] = {30, 32, 34, 36};

Keypad keypad = Keypad( makeKeymap(hexaKeys), pin_rows, pin_cols, ROWS, COLS );

const String pin = "1234"; // change your password here
String input_pin;

void setup(){
  lcd.clear();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Enter the pin: ");
  
}

void loop(){
 
  char key = keypad.getKey();

  if (key){
    lcd.setCursor(lcd_col,lcd_row);
    lcd.print(key);
    lcd_col++;
    if(key == '*') {
      input_pin = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter the pin: ");
      lcd.setCursor(0, 1);
      lcd_col = 0;
      lcd_row = 1;
    } 

    else if(key == '#') {
      if(pin == input_pin) {
        lcd.clear();
        lcd_col = 0;
        lcd_row = 0;
        lcd.setCursor(0,0);
        lcd.print("pin is correct");
        // DO YOUR WORK HERE
        
      } else {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("pin is incorrect");
        lcd.setCursor(2, 1);
        lcd.print("try again");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Enter the pin: ");
        lcd_col = 0;
        lcd_row = 1;
        lcd.setCursor(0,1);
      }

      input_pin = ""; // clear input password
    } else {
      input_pin += key; // append new character to input password string
    }
  }
}
