#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
String input;
String password="123#";

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
reset();
}

void loop() {
  // put your main code here, to run repeatedly:
char key = keypad.getKey();
if(key!=NO_KEY)
{
  input=input+key;
lcd.print(key);
lcd.print('*');
if(key=='#')
{
  if(input==password)
{
lcd.setCursor(0,1);
lcd.print("CORRECT PASSWORD");
}
else
{
  lcd.setCursor(0,1);
  lcd.print("TRY AGAIN");
}
delay(2000);
input="";
reset();
}
}
}
void reset()
{
lcd.clear();
lcd.print("Enter Password");
lcd.setCursor(0,1);
}