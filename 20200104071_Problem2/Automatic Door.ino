#include <Servo.h>
Servo servo;
int buzzer = 9;

const int sigPin =7;
long duration;
int distance;

int angle= 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  int angle=0;
  
    servo.attach(8);
    servo.write(angle);

Serial.begin(9600);
}

void loop() {

  pinMode(sigPin,OUTPUT);
  digitalWrite(sigPin,LOW);
  delay(2);
  digitalWrite(sigPin,HIGH);
  delay(10);
  digitalWrite(sigPin,LOW);
  pinMode(sigPin,INPUT);
  duration=pulseIn(sigPin,HIGH);
  distance=(duration*0.034)/2;
  Serial.print("D(cm): ");
  Serial.println(distance);
  if(distance<10)	
  {
    for(angle=0;angle<180;angle++)
  	{
    	servo.write(angle);
    	tone(buzzer,1000);

  	}
  }
  else 
  {
    for(angle=180;angle>0;angle--)
  	{
      	servo.write(angle);
      	noTone(buzzer);
  	}
  }

  delay(10);
}



