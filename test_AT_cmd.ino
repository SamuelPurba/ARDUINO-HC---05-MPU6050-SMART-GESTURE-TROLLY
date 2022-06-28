/*
 ASCII table
 Prints out byte values in all possible formats:
 - as raw binary values
 - as ASCII-encoded decimal, hex, octal, and binary values
 For more on ASCII, see http://www.asciitable.com and http://en.wikipedia.org/wiki/ASCII
 The circuit: No external hardware needed.
 created 2006
 by Nicholas Zambetti <http://www.zambetti.com>
 modified 9 Apr 2012
 by Tom Igoe
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/ASCIITable
*/

void setup() {

 Serial.begin(9600);

while (!Serial) {
   ; // wait for serial port to connect. Needed for native USB port only
 }

 Serial.println("ASCII Table ~ Character Map");
}

int thisByte = 33;

void loop() {

 Serial.write(thisByte);

 Serial.print(", dec: ");
 Serial.print(thisByte);

 Serial.print(", hex: ");
 Serial.print(thisByte, HEX);

 Serial.print(", oct: ");
 Serial.print(thisByte, OCT);

 Serial.print(", bin: ");
 Serial.println(thisByte, BIN);

 if (thisByte == 126) {   
   while (true) {
     continue;
   }
 }
 thisByte++;

}
