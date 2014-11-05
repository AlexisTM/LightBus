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
  if(adress > 7) adress = 7;
  MyAdress = adress;
  Serial.begin(57600);
  Serial.setTimeout(2);
}

void LightBusSlave::Update(){
  // Got a packet?
  if(Serial.available() > 2){
    byte adrfunc;
    adrfunc = (byte)Serial.read();
    // Do we got a 1?
    if(!IsSync(adrfunc)){
      // If no, try to resync and check the next packet
      adrfunc = (byte)Serial.read();
      // If still not sync, return and wait the next call.
      // else, go on!
      if(!IsSync(adrfunc)) return;
    }
    // Is this packet for me?
    if(!IsForMe(adrfunc)){
      // If it is NOT for me, flush it
      Serial.read();
      return;
    }
    byte data;
    data = (byte)Serial.read();
    // Set the data in the main
    TodoBuffer[0] = adrfunc;
    TodoBuffer[1] = data;
    // Check our job to do
    WhatIsTheJob();
  }
}

inline boolean LightBusSlave::IsSync(byte adrfunc)
{
  // Check the first bit of the byte
  if((adrfunc & 128)) return true;
  return false;
}

inline boolean LightBusSlave::IsForMe(uint8_t adress)
 // Check if the 3 bits of the adress meets our adress
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

