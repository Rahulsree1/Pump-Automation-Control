#include "./Alarm.h"
void Auto(bool &mflag, bool &tempflag,int &lev,int minlev,int maxlev,int &pvalue, bool &pflag, int &bw){
  if(mflag){
    // Code for Auto
    tempflag = true;
    if(lev<minlev || lev<maxlev){
      pvalue = 1;
      pflag = true;
      Blynk.virtualWrite(V2, 1);
    }else if(lev>maxlev){
      pvalue = 0;
      pflag = false;
      Blynk.virtualWrite(V2, 0);
      
    }else{
      pvalue = 0;
      pflag = false;
      Blynk.virtualWrite(V2, 0);
    }
    
  }else{
    //Code for Manual
    if(tempflag){
      pvalue = 0;
      pflag = false;
      Blynk.virtualWrite(V2, 0);
      tempflag = false;
      }
    if(lev<minlev){
      Blynk.logEvent("overflow","Water is below Min level");
    }
    if(lev>maxlev && pflag == true){
      alrm(500,bw);
    }
    
  }
}