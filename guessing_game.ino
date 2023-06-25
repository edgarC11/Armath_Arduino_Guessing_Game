#include <Keypad.h>
#include <LiquidCrystal.h>


const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {22, 24, 26, 28}; 
byte colPins[COLS] = {30, 32, 34, 36};    


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  


int randomNumber;
int userGuess;
boolean gameWon = false;

void setup() {
  randomSeed(analogRead(A0));   

  lcd.begin(16, 2);             
  lcd.setCursor(0, 0);
  lcd.print("Guess the Number");

  randomNumber = random(1, 10);  
}

void loop() {
  char key = keypad.getKey();   
  lcd.setCursor(0, 1);
  if (key != NO_KEY) {
    if (isdigit(key)) {
      userGuess = userGuess * 10 + (key - '0');   
      lcd.print(key);
    } else if (key == '#') {
      
      if (userGuess == randomNumber) {
        lcd.clear();
        lcd.print("Correct!");
        gameWon = true;
      } else if (userGuess < randomNumber) {
        lcd.clear();
        lcd.print("Too low!");
        
      } else {
        lcd.clear();
        lcd.print("Too high!");
      }

      delay(2000);

      if (gameWon) {
   
        randomNumber = random(1, 10);
        gameWon = false;
      }

      
      userGuess = 0;
      lcd.clear();
      lcd.print("Guess the Number");
    }
  }
}
