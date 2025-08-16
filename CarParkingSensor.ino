int buzzpin=9;
int trigpin=11;
int echopin=12;
int pingtime;
float onewaypingtime;
float distance;
void setup() {
Serial.begin(9600);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(buzzpin, OUTPUT);
}
void loop() {
digitalWrite(trigpin, LOW);
delayMicroseconds(10);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
pingtime=pulseIn(echopin, HIGH);
onewaypingtime=pingtime/2;
distance=onewaypingtime*.0345;
Serial.println(distance);
if(distance<5){
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
digitalWrite(buzzpin, HIGH);
delay(150);
digitalWrite(buzzpin, LOW);
delay(150);}
else if (distance < 15){
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
digitalWrite(buzzpin, HIGH);
delay(300);
digitalWrite(buzzpin, LOW);
delay(300);
}
else if (distance < 20){
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(buzzpin, HIGH);
delay(500);
digitalWrite(buzzpin, LOW);
delay(500);
}


}
