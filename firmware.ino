#include <OneButton.h>
#include "./level.h"
#include "./Automation.h"
#include "./Alarm.h"
#include "Mode.h"

#define BLYNK_TEMPLATE_ID "TMPL3uHGYzRdH"
#define BLYNK_TEMPLATE_NAME "Water Automation"
#define BLYNK_AUTH_TOKEN "WY1zWmBMMiiYsyJwktIckAL5u4X4ZizR"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int distance;
long duration;
int t = 105;
bool tempflag;
int mvalue;
char ssid[] = "Le25hz";
char pass[] = "Eswar9966";
int pvalue;
int lev;
int minlev = 20;
int maxlev = 100;
#define trig D0
#define echo D1
#define g D2
#define b D3
#define r D4
#define bw D5
#define mod D6
#define pump D7
#define relay D8

OneButton modbutton(mod, true); 
OneButton pumpbutton(pump, true);

bool mflag = false;
bool pflag = false;



void pumpof(){
  Serial.println("pump Detected");
  if(pvalue == 1){
    pvalue = 0;
    pflag = false;
    Blynk.virtualWrite(V2, 0);
  }else{
    pvalue = 1;
    pflag = true;
    Blynk.virtualWrite(V2, 1);
  }
}

void pumpONOFF(){
  if(pflag){
    digitalWrite(relay,HIGH);
    digitalWrite(r,HIGH);
    Blynk.virtualWrite(V3, 1);
  }else{
    digitalWrite(relay,LOW);
    digitalWrite(r,LOW);
    Blynk.virtualWrite(V3, 0);
  }
}







BlynkTimer timer;
BLYNK_WRITE(V0){
  mvalue = param.asInt();
  if(mvalue == 1){
    mflag = true;
    digitalWrite(g,HIGH);
    digitalWrite(b,LOW);
    
  }else{
    mflag = false;
    digitalWrite(b,HIGH);
    digitalWrite(g,LOW);
  }
  
}
BLYNK_WRITE(V2){
  pvalue = param.asInt();
  if(pvalue == 1){
    pflag = true;
    digitalWrite(r,HIGH);
    digitalWrite(relay,HIGH);
    Blynk.virtualWrite(V3, 1);
    
  }else{
    pflag = false;
    digitalWrite(r,LOW);
    digitalWrite(relay,LOW);
    Blynk.virtualWrite(V3, 0);
    
  }
  
}

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.begin(115200);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(bw,OUTPUT);
  pinMode(mod,INPUT);
  pinMode(pump,INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(b,HIGH);
  Blynk.virtualWrite(V0, 0);
  Blynk.virtualWrite(V2, 0);
  mflag = false;
  pflag = false;
  modbutton.attachLongPressStop(changmode);
  pumpbutton.attachLongPressStop(pumpof);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  level(distance,duration,lev,t);
  modbutton.tick();
  pumpbutton.tick();
  pumpONOFF();
  Auto(mflag,tempflag,lev,minlev,maxlev,pvalue,pflag,bw);
  
  
}
