#include "deneyap.h" //Deneyap Geliştirme Kartı kütüphanesinin programa 

#include <ESP32Servo.h> //Servo motor kütüphanesinin programa eklenmesi

#define sag_led D4 //servo motorun bağlandığı D0 pininin tanımlaması
#define sol_led D8
#define L1_pin D14 //sağ ışık sensörünün bağlandığı D14 pininin tanımlaması
#define L2_pin D15 //sol ışık sensörünün bağlandığı D15 pininin tanımlaması

Servo myservo1; //servo motora ilişkin değişken tanımlaması

int sensor1, sensor2; //LDR’lerin değişkenlerinin tanımlanması
int pos = 0; //servo motor pozisyonuna ilişkin değişken tanımlaması

void setup() 
{
  pinMode(sol_led, OUTPUT);
  pinMode(sag_led, OUTPUT);
  myservo.attach(SERVOPIN);

}

void loop() {
  sensor1 = digitalRead(L1_pin); //sağ ışık sensöründen gelen dijital verinin okunması
 sensor2 = digitalRead(L2_pin); //sol ışık sensöründen gelen dijital verinin okunması

 if (sensor1>sensor2) //sağ LDR’ye düşen ışık > sol LDR’ye düşen ışık
 {
 digitalWrite(sag_led,1);
 digitalWrite(sol_led,0);
 }
 else if(sensor2>sensor1) //sol LDR’ye düşen ışık > sağ LDR’ye düşen ışık
 {
 digitalWrite(sag_led,0);
 digitalWrite(sol_led,1);
 }
 else if(sensor2=sensor1) //sağ LDR’ye düşen ışık = sol LDR’ye düşen ışık
 {
 digitalWrite(sag_led,1);
 digitalWrite(sol_led,1);
 }
delay(5);
}


