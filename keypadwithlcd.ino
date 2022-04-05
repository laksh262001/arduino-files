#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
/*CONNECTIONS FOR LCD TO ARDUINO
LCD                       ARDUINO
1,3,5,16                    GND
2,15                        5V
4                           D2
6                           D3
7,8,9,10                    No Connection
11                          D4
12                          D5
13                          D6
14                          D7
*/
const byte ROWS= 4;
const byte COLS = 4;
char keys[ROWS][COLS]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {8,9,10,11};
byte colPins[COLS] = {12,13,A0,A1};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
char key = keypad.getKey();
if(key!=NO_KEY){
lcd.print(key);
}
}
