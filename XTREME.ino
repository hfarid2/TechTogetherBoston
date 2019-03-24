float temp;
int tempPin = 0;
int fanPin = 7;
int ledPin = 8;

void setup() {
   Serial.begin(9600);
   pinMode(fanPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
}

void loop() {
   temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   // calibration nonsense ie I Want To Cry
   temp -= 200;
   temp /= 25.0;
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();

   // turn on the fan if temperature is above 22 deg 
   // turn on the LED if temperature is below 19 deg
   if (temp < 19) {
     digitalWrite (ledPin, HIGH);
     digitalWrite (fanPin, LOW);
   }
   else if (temp > 22) {
     digitalWrite (ledPin, LOW);
     digitalWrite (fanPin, HIGH);
   }
   else {
     digitalWrite (ledPin, LOW);
     digitalWrite (fanPin, LOW);
   }
   
   delay(3000); // update sensor reading each three seconds
}
