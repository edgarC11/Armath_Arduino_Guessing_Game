#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const byte rows = 4;
const byte cols = 4;

byte lcd_col = 0;
byte lcd_row = 0;

char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {22, 24, 26, 28}; 
byte colPins[cols] = {30, 32, 34, 36};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols); 

void setup()
{
  lcd.clear();
  lcd.begin(16,2);
}

void loop()
{
  char customKey = customKeypad.getKey();
  lcd.setCursor(lcd_col,lcd_row);

  if (customKey)
  {
    lcd.print(customKey);
    lcd_col++;
  }
  if(lcd_col == 16 && lcd_row == 0)
  {
    lcd.setCursor(0,1);
    lcd_col = 0;
    lcd_row = 1;
  }
  if(lcd_col == 16 && lcd_row == 1)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd_col = 0;
    lcd_row = 0;
  }

}

