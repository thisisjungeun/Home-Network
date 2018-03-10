#include <SoftwareSerial.h> 
#include <Servo.h>
#include <String.h>
int d = 0;
char id[400] = {0};
int a = 0;
int i = 0;
int p = 1;
 int doorLight = 8;
 Servo servo;
SoftwareSerial BTSerial(2, 3); // SoftwareSerial(RX, TX) 
void initIdBuffer(char id[400]) {
  int i;
  
  for (i = 0; i  < 400; i++)
    id[i] = 0;
}

void setup() 
{ 
 Serial.begin(9600); 
 Serial.println("Hello!"); 
 BTSerial.begin(9600); 
  pinMode(doorLight, OUTPUT);

  servo.attach(9);
  servo.write(170);
  servo.detach(); 
  
} 

void loop(){ 

if(a == 0){
   //Serial.println(i);
  delay(300);
  servo.detach();
  BTSerial.print("AT+DISI?");
 }

 while (BTSerial.available()){ // if BT sends something 
 id[i] = BTSerial.read(); 
 // Serial.write(id[i]); // write it to serial(serial monitor) 
 i++;
}

delay(1);
while (Serial.available()){ // if Serial has input(from serial monitor) 
 char data = Serial.read(); 
 BTSerial.write(data); 
}


if( i > 300){
i = 0;
for(int j = 0; j < 300; j++){
  if(id[j] =='E'){ 
    int p1 = j; p1++;
      if(id[p1] == 'F'){
          int p2 = p1;  p2++;
            if(id[p2] == 'F'){
              int p3 = p2; p3++;
                if(id[p3] == 'C'){
                  p3++;
                  p3++;
                  p3++;
                  
                  p3++;
                //  Serial.write(id[p3]);
                  d = ((int)id[p3] - 48)*10;
                   p3++;
                  int p4 = p3;
              //    Serial.write(id[p4]);
                  Serial.println("");
                  d = d + (int)id[p4]-48;
                  Serial.println(d);
                  initIdBuffer(id);
                  
                  if(d < 40){
                            Serial.println("OPEN!"); 
                            servo.attach(9);
                            servo.write(130);   
                           }
                  else{
                            Serial.println("CLOSE!"); 
                            servo.attach(9);
                            servo.write(170);   
                           }
                  break;
                  }
              }
          }
      }
  }
}


 a++;
   if(a > 10){
    a = 0;
    }
 delay(100);
 }

 





 
