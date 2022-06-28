#include <SoftwareSerial.h> // inclue library software serial
#define tx 3
#define rx 2
SoftwareSerial BlueLED(rx, tx); //RX, TX
char data;

int lm1=8; //left motor output 3
int lm2=9; //left motor output 4
int rm1=10;  //right motor output 1
int rm2=11;  //right motor output 2


void setup() {

  //pinMode(13, OUTPUT); // mengatur pin 13 sebagai pin output
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  
  Serial.begin(9600); // mengatur boudrate komunikasi serial
  BlueLED.begin(9600); // mengatur boaudrate serial modul bluetooth
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);

    sTOP();
     
}

 

void loop() 
  {
    //ForWard();
    if (BlueLED.available()>0) // jika ada data serial dari modul bluetooth
      {
       data = BlueLED.read(); // simpan data itu di variable ‘data’
       Serial.println(data); // print variable data ke serial monitor
      
   if(data=='F')
   {
     ForWard();
     Serial.println('F');
   }
    if(data=='B')
     {
   BackWard();
   Serial.println('B');
    }
    
  if(data=='L')
  {
   Left();
   Serial.println('L');
    }
  if(data=='R')
  { 
  Right();
  Serial.println('R');
   }
     if(data=='S')
     
  {
   sTOP();
   Serial.println('S');
    }
    }
}

  
 void ForWard()
  {
   digitalWrite(lm1,250);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,250);
   digitalWrite(rm2,LOW);
   Serial.println("MAJU");
  } 
  void BackWard()
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,250);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,250);
   Serial.println("MUNDUR");
  }
  void Left()
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,250);
   digitalWrite(rm1,250);
   digitalWrite(rm2,LOW);
   Serial.println("KIRI");
  } 
  void Right()
  {
   digitalWrite(lm1,250);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,250);
   Serial.println("KANAN");
  }  

    void sTOP()
  {
   digitalWrite(lm1,LOW);
   digitalWrite(lm2,LOW);
   digitalWrite(rm1,LOW);
   digitalWrite(rm2,LOW);
   Serial.println("STOP");
  }  
    
