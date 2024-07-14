void changmode(int &mvalue, bool &mflag){
  Serial.println("Detected");
  if(mvalue == 1){
    mvalue = 0;
    mflag = false;
    digitalWrite(b,HIGH);
    digitalWrite(g,LOW);
    Blynk.virtualWrite(V0, 0);
  }else{
    mvalue = 1;
    mflag = true;
    digitalWrite(g,HIGH);
    digitalWrite(b,LOW);
    Blynk.virtualWrite(V0, 1);
  }
}