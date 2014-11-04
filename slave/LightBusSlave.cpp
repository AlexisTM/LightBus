#include "LightBusSlave.h"

LightBusSlave::LightBusSlave(){
}

// Define dummy functions
void Function0(uint8_t data){}
void Function1(uint8_t data){}
void Function2(uint8_t data){}
void Function3(uint8_t data){}
void Function4(uint8_t data){}
void Function5(uint8_t data){}
void Function6(uint8_t data){}
void Function7(uint8_t data){}
void Function8(uint8_t data){}
void Function9(uint8_t data){}
void Function10(uint8_t data){}
void Function11(uint8_t data){}
void Function12(uint8_t data){}
void Function13(uint8_t data){}
void Function14(uint8_t data){}
void Function15(uint8_t data){}

void LightBusSlave::Begin(int baudrate, uint8_t adress)
{
  MyAdress = adress;
  Serial.begin(57600);
  Serial.setTimeout(2);
}

void LightBusSlave::Update(){
  // Got a packet?
  char adrfunc;
  char data;
  if(Serial.available() > 2){
    adrfunc = (char)Serial.read();
    if(IsForMe(Serial.read())){
      data = (char)Serial.read();
      TodoBuffer[0] = adrfunc;
      TodoBuffer[1] = data;
      WhatIsTheJob();
    } else {
      Serial.read();
    }
  }
}

inline boolean LightBusSlave::IsForMe(uint8_t adress)
{
  adress = ADRESS(adress);
  if((adress) = MyAdress) return true;
  return false;
}

void LightBusSlave::WhatIsTheJob(){
  uint8_t func = FUNCTION(TodoBuffer[0]);
  uint8_t data = TodoBuffer[1];
  switch (func){
  case 0 :
    Function0(data);
    break;
  case 1 :
    Function1(data);
    break; 
  case 2 :
    Function2(data);
    break; 
  case 3 :
    Function3(data);
    break; 
  case 4 :
    Function4(data);
    break; 
  case 5 :
    Function5(data);
    break; 
  case 6 :
    Function6(data);
    break; 
  case 7 :
    Function7(data);
    break; 
  case 8 :
    Function8(data);
    break; 
  case 9 :
    Function9(data);
    break; 
  case 10 :
    Function10(data);
    break; 
  case 11 :
    Function11(data);
    break; 
  case 12 :
    Function12(data);
    break; 
  case 13 :
    Function13(data);
    break; 
  case 14 :
    Function14(data);
    break; 
  case 15 :
    Function15(data);
    break; 
  default:
    break;
  }
}

