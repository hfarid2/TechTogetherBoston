/*
 * TechTogetherBoston 
 * BOSTON LET'S GET I T
 * Project: 
 * contributers: Hiba Farid, Tatiana Carbajal, 
 * WHAT:
 * WHY:
 * HOW: 
 * 
 * what this code does: 
 * Applications in the real world:
 * 
 */

float temp;
int tempPin = 0;
int ledPin = 8;

void setup() {
   Serial.begin(9600);
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

   // turn on the LED if temperature is above 22 deg 
   if (temp > 22) {
     digitalWrite (ledPin, HIGH);
   }
   else
     digitalWrite (ledPin, LOW);
   
   delay(3000); // update sensor reading each three seconds
}
