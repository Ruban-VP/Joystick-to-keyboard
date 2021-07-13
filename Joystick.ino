#include <BleKeyboard.h>

BleKeyboard Key; 
boolean state = !false;

void setup() {
  Serial.begin(9600);
  Key.begin();
}

void loop() {
  
  int x = analogRead(32);
  int y = analogRead(34);
  /*
  int trig = analogRead(35);
   
  if(trig==0){
    state = (!state);
  }
  */
  Serial.println(x);
  Serial.println(y);
  //Serial.println(trig);
  Serial.println(state);
  Serial.println("------------------------");

  if(Key.isConnected()){
    if(state==true){
      if(x>=1024 && x<=3072 && y==0){
        Key.releaseAll();
        Key.press('W');
      }
      else if(y>=1024 && y<=3072 && x==0){
        Key.releaseAll();
        Key.press('A');
      }
      else if(x>=1024 && x<=3072 && y==4095){
        Key.releaseAll();
        Key.press('S');
      }
      else if(y>=1024 && y<=3072 && x==4095){
        Key.releaseAll();
        Key.press('D');
      }
      else if(x<1024 && y<1024){
        Key.releaseAll();
        Key.press('W');
        Key.press('A');
      }
      else if(x<1024 && y>3072){
        Key.releaseAll();
        Key.press('S');
        Key.press('A');
      }
      else if(x>3072 && y>3072){
        Key.releaseAll();
        Key.press('S');
        Key.press('D');
      }
      else if(x>3072 && y<1024){
        Key.releaseAll();
        Key.press('W');
        Key.press('D');
      }
      else{
        Key.releaseAll();
      }
    }
  }
  else{
    Serial.println("Bluetooth not connected");
  }
  delay(1);
}
