void level(int &distance, long &duration, int &lev, int t){
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);

distance=duration*0.017;
lev = (t-distance);

Serial.println(lev);
Blynk.virtualWrite(V1, lev);

}