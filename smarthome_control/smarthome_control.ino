#include <SoftwareSerial.h>
#include <Servo.h>
int INA = 9;
int INB = 8;
SoftwareSerial BTSerial(2, 3); //Connect HC-06. Use your (TX, RX) settings

Servo servo;
char c=0;
void setup()  
{ pinMode(13, OUTPUT); digitalWrite(13, LOW);
  pinMode(12, OUTPUT); digitalWrite(12, LOW);
  pinMode(11, OUTPUT); digitalWrite(11, LOW);
  pinMode(10, OUTPUT); digitalWrite(10, LOW);
  pinMode(7, OUTPUT);  digitalWrite(7, LOW);
  delay(10);
  Serial.begin(9600);
  Serial.println("Hello!");
  pinMode(INA,OUTPUT);  digitalWrite(INA,LOW);
  pinMode(INB,OUTPUT);  digitalWrite(INA,LOW);
  
  servo.attach(5);
  servo.write(0);
  servo.detach(); 
  BTSerial.begin(9600);  // set the data rate for the BT port
  delay(10);
}
 
void loop()
{
  // BT –> Data –> Serial
  if (BTSerial.available()) {
   c = BTSerial.read();   
    Serial.write(c);
    switch(c){
    case 'A': 
            digitalWrite(13, HIGH); 
            break;
    case 'B':
            digitalWrite(13, LOW);
            break;
    case 'C':
            digitalWrite(12, HIGH);
            break;
    case 'D':
            digitalWrite(12, LOW);
            break;
    case 'E':
            digitalWrite(11, HIGH);
            break;
    case 'F':
            digitalWrite(11, LOW);
            break;
    case 'G':
            digitalWrite(10, HIGH);
            break;
    case 'H':
            digitalWrite(10, LOW);
            break;
    case 'I':
            digitalWrite(7, HIGH);
            break;
    case 'J':
            digitalWrite(7, LOW);
            break;        
    case 'K':
            digitalWrite(INA,LOW);
            digitalWrite(INA,HIGH);  
            break;
    case 'L':
            digitalWrite(INA,LOW);
            digitalWrite(INA,LOW);
            break;
    case 'N':
            servo.attach(5);
            servo.write(90);   
            delay(500);
            servo.write(0);   
            delay(500);
            servo.detach();
            break;
     case 'M':
            servo.attach(5);
            servo.write(90);
            delay(500);
            servo.write(170);
            delay(500);
            servo.detach();
            break;
    default:
            delay(50);
            break;
  }   
  }
  // Serial –> Data –> BT
  if (Serial.available()) {
   c = Serial.read();   
    Serial.write(c);
  }

delay(1);

}
