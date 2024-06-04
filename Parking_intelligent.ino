
#include <HCSR04.h>
#include <LiquidCrystal.h>

#include <Servo.h>
int i=10;
LiquidCrystal lcd(14,15,16,17,181,9); 
Servo servo;
const int servoPin=13;
const int trig1Pin = 2;
const int echo1Pin = 3;
const int trig2Pin = 4;
const int echo2Pin = 5;
const int LEDrouge=6;
const int LEDvert=7;
int position = 180;
UltraSonicDistanceSensor distanceSensor1(trig1Pin, echo1Pin);
UltraSonicDistanceSensor distanceSensor2(trig2Pin, echo2Pin);
 
void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.blink();
  lcd.print("Welcome");
servo.attach(servoPin);
pinMode(LEDrouge,OUTPUT); 
pinMode(LEDvert,OUTPUT);
Serial.begin(9600); 
}
 
void loop(){
  lcd.setCursor(2,1);
  lcd.blink();
  lcd.println("nb spot=");
  lcd.print(i);
  Serial.print(distanceSensor1.measureDistanceCm()+1);
Serial.println("cm");
if(((((distanceSensor1.measureDistanceCm()+1)<6)&&(distanceSensor1.measureDistanceCm()+1)>0))||((distanceSensor2.measureDistanceCm()+1<6)&&(distanceSensor2.measureDistanceCm()+1)>0)) {// Si l'un des deux capteurs HC-SR04 détecte un véhicule
servo.write(90); // la barrière s'ouvre
digitalWrite(LEDrouge,LOW);
digitalWrite(LEDvert,HIGH); // La LED s'allume en vert
i--;
lcd.setCursor(0,1);
lcd.blink();
lcd.println("place disp");
lcd.print(i);



 
}else
{
servo.write(180); // la barrière se ferme
digitalWrite(LEDrouge,HIGH); // led s'allume en rouge
digitalWrite(LEDvert,LOW); 
i++;
lcd.clear();
lcd.setCursor(0,1);
lcd.blink();
lcd.println("place disp");
lcd.print(i);

}

if(i==0){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.blink();
  lcd.print("sorry no spot :)");
 
}
 
}
