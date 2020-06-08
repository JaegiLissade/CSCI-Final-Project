#include <Adafruit_CircuitPlayground.h>
//morse code messages: SOS, danger, im hurt, hi, bye, yes, no
String message[] = { "11102220111", "2110120210221010121", "1102200011110112012101", "1111011", "21110212201", "2122010111", "210111"};


//colorall
void colorAll(int r, int g, int b){
  for(int i =0; i<10; i++){
   CircuitPlayground.setPixelColor(i,r,g,b);
  }}

void display(int num){
  //light
if (CircuitPlayground.slideSwitch() == 0 ){
  for(int i = 0; i < message[num].length();i++){
    if(message[num][i]== '1'){
      Serial.println("1");
      colorAll(255,0,0);
      delay(1000);
     CircuitPlayground.clearPixels();
     delay(1000);
      
    }
     else if(message[num][i]== '2'){
      Serial.println("2");
      colorAll(0,255,0);
      delay(2000);
      CircuitPlayground.clearPixels();
      delay(2000);
    }
    else if(message[num][i]== '0'){
      Serial.println("0");
      colorAll(0,0,0);
      delay(1000);
      CircuitPlayground.clearPixels();
      delay(2000);
    }else{
      CircuitPlayground.clearPixels();
      

    
  }
}

}
//sound
if(CircuitPlayground.slideSwitch() == 1 ){
for(int i = 0; i < message[num].length();i++){
    if(message[num][i]== '1'){
      Serial.println("1");
      CircuitPlayground.playTone(400,300);
      delay(500);
    }
     else if(message[num][i]== '2'){
      Serial.println("2");
      CircuitPlayground.playTone(250, 600);
      delay(500);
    }
    else if(message[num][i]== '0'){
      Serial.println("0");
      delay(1000);
     
    } 
  }
}

}

void setup() {
  // put your setup code here, to run once:
CircuitPlayground.begin();



}

 // touch pad to message relations

void loop() {

CircuitPlayground.clearPixels();
    //touch pads
     if(CircuitPlayground.readCap(3)>400){
   display(0);
}else if(CircuitPlayground.readCap(2)>400){
  display(1);
}else if(CircuitPlayground.readCap(0)>400){
  display(2);
}else if(CircuitPlayground.readCap(1)>400){
  display(3);
}else if(CircuitPlayground.readCap(12)>400){
   display(4);
}else if(CircuitPlayground.readCap(6)>400){
  display(5);
}else if(CircuitPlayground.readCap(9)>400){
  display(6);
}


}
