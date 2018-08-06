/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A3);
  int sensorValue2 = analogRead(A4);
  int sensorValue3 = analogRead(A5);
  int sensorValue4 = analogRead(A6);
  int sensorValue5 = analogRead(A7);
  
  // print out the value you read:
  Serial.println(sensorValue1);
   Serial.println(sensorValue2);
    Serial.println(sensorValue3);
     Serial.println(sensorValue4);
      Serial.println(sensorValue5);
   Serial.println(" ");
  delay(1);        // delay in between reads for stability
}
