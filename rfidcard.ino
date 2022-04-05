#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); // Parameters:(rs,enable,d4,d5,d6,d7)
/* 
  RFID MODULE      ARDUINO
  3.3V              Pin 3.3v
  RST               Pin 9
  GND               GND
  NC                No Connection
  MISO              Pin 12
  MOSI              Pin 11
  SCK               Pin 13
  SDA               Pin 10
*/
/* CONNECTIONS FOR LCD TO ARDUINO
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

#define RST_PIN 9          // Configurable, see typical pin layout above
#define SS_PIN  10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  reset();
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Show your card to the reader");
  Serial.println("Thank you :-)");
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

Serial.print("UID tag :");
String content="";
byte letter;
for(byte i=0;i< mfrc522.uid.size;i++)
{
  Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " ");
  Serial.print(mfrc522.uid.uidByte[i],HEX);
  content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : " "));
  content.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  Serial.println();
  Serial.println("Message :");
  content.toUpperCase();
  if (content.substring(1) == "D3 FB01 15") // to add more cards just use or logic ex: if (content.substring(1) == "11 22 33" ||content.substring(1) == "11 22 33" ) like this
  {
    Serial.println("Authorised Acess");
    Serial.println();

     //function for lcd
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print('Authorised');
    //lcd.display();
    lcd.setCursor(0,1);
    lcd.print('Opening Lock....');
    delay(3000);
    }

   else   {
    Serial.println("Access Denied!!");

     //function for lcd
    //lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("UnAuthorised");
    //lcd.display();
    lcd.setCursor(0,1);
    lcd.print("Wrong Card!..");
    
    // u can use buzzer to sound here...
    }
    delay(3000);
    input="";
    reset();
}
}
void reset()
{
  lcd.clear();
  lcd.print("show card");
  lcd.setCursor(0,1);
  }