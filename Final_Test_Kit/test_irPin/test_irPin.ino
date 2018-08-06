

void setup() {

pinMode(10,INPUT);
  
  Serial.begin(9600);

}

void loop() {
int R = digitalRead(10);//RIGHT
Serial.print(R);
Serial.print("\n");
}
