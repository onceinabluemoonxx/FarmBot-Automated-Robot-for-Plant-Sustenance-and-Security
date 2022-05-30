int sensorPin = A0; 
int sensorValue;  
int limit = 800; 
int motor = A1;


void setup() {
 Serial.begin(9600);
  pinMode(motor, OUTPUT);
}

void loop() {

 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 
 if (sensorValue<limit) {
 analogWrite(motor, 1200);  
 }
 else {
 analogWrite(motor, 0); 
 }
 
 delay(1000); 
}
