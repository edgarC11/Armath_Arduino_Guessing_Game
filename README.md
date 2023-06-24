Go over project 22 from the elegoo guide on the lcd display.

LCD display wiring:

VSS -> GND
VDD - > 5V
VE -> potentiometer
RS -> D7
RW - > GND
E -> D8
D0 - D3 -> Skip
D4 -> D9
D5 -> D10
D6 -> D11
D7 -> D12
BA -> 5V
BC -> GND

byte rowPins[ROWS] = {22, 24, 26, 28}; 
byte colPins[COLS] = {30, 32, 34, 36};
