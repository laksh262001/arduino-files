#define IR A0
int x;
int LED = 13;
void setup() {
Serial.begin(9600);
pinMode(IR,INPUT);
pinMode(LED,OUTPUT);
}

void loop() {
  x = analogRead(IR);
Serial.println(x);
if(x<=22)
{
 digitalWrite(LED, HIGH);
}
else{
digitalWrite(LED, LOW);
}
delay(500);

}
