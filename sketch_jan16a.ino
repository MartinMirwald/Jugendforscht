int trig=D1;
int echo=D0;
int motor=D5;
int sensorPin = A0;
long zeit=0;
long entfernung=0;
int sensorValue = 0;
void setup() {
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(motor, OUTPUT);
Serial.begin (9600);
}
void loop() {
sensorValue = analogRead(sensorPin);
sensorValue=sensorValue/100;
digitalWrite(trig, LOW);
delay(5);
digitalWrite(trig, HIGH);
delay(10);
digitalWrite(trig, LOW);
zeit=pulseIn(echo, HIGH);
entfernung=(zeit/2)*0.03432;
if (entfernung >= 500 || entfernung <= 0) 
{Serial.println(sensorValue);
Serial.println("Kein Messwert"); 
}
else 
{
Serial.print(entfernung); 
Serial.println(" cm");
Serial.println(sensorValue);
}
if(entfernung<=10*sensorValue&&entfernung>=0){
analogWrite(motor,0);
}
else if(entfernung<=20*sensorValue&&entfernung>=10*sensorValue){

analogWrite(motor,100);
}
else if(entfernung<=30*sensorValue&&entfernung>=20*sensorValue){
analogWrite(motor,200);
}
else {
digitalWrite(motor,HIGH);}
delay(10);
}
