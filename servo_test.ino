#include <Servo.h>

Servo fan; // servo motor acts as fan
int pos = 0; // stores servo position
float temp;
int tempPin = 0;
int fanPin = 7;
int ledPin = 8;

void setup() {
   Serial.begin(9600);
   //pinMode(fanPin, OUTPUT);

   fan.attach(fanPin);
   pinMode(ledPin, OUTPUT);
}

void spin() {
  for (pos = 0; pos <= 180; pos++) {
    fan.write(pos);
  }
  for (pos = 180; pos >= 0; pos--) {
    fan.write(pos);
  }
}

void loop() {
   temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   // calibration nonsense
   temp -= 0;
   temp /= 30.0;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();

   // turn on the fan if temperature is above 20 deg 
   if (temp < 20) {
     digitalWrite (ledPin, HIGH);
   }
   else if (temp > 20) {
     digitalWrite (ledPin, LOW);
     while (temp > 20) {
       //spin();
       temp = analogRead(tempPin);
       temp /= 30.0;
     }
   }
   else {
     digitalWrite (ledPin, LOW);
   }
   
   delay(3000); // update sensor reading each three seconds
}
