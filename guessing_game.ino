#include <Keypad.h>
#include <LiquidCrystal.h>

// Define the keypad connections and keys
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {22, 24, 26, 28}; 
byte colPins[COLS] = {30, 32, 34, 36};    // Connect to the column pinouts of the keypad

// Create an instance of Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the LCD connections
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  // Set the LCD address to 0x27 for a 16x2 display

// Game variables
int randomNumber;
int userGuess;
boolean gameWon = false;

void setup() {
  randomSeed(analogRead(A0));   // Seed the random number generator with an analog pin reading

  lcd.begin(16, 2);             // Initialize the LCD display
  lcd.setCursor(0, 0);
  lcd.print("Guess the Number");

  randomNumber = random(1, 10);  // Generate a random number between 1 and 100
}

void loop() {
  char key = keypad.getKey();   // Read the keypad input
  lcd.setCursor(0, 1);
  if (key != NO_KEY) {
    if (isdigit(key)) {
      userGuess = userGuess * 10 + (key - '0');   // Build up the user's guess
      lcd.print(key);
    } else if (key == '#') {
      // Check the user's guess
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
        // Game won, generate a new random number and restart the game
        randomNumber = random(1, 10);
        gameWon = false;
      }

      // Reset variables and LCD display
      userGuess = 0;
      lcd.clear();
      lcd.print("Guess the Number");
    }
  }
}