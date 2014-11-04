#include "LightBusSlave.h"
/*

RAPPEL POINTEURS : 
http://www.cplusplus.com/doc/tutorial/pointers/
& is the address-of operator, and can be read simply as "address of"se
* is the dereference operator, and can be read as "value pointed to by"

*/

// 5 bytes for data is the maximum!
LightBusSlave LightBus;

void setup()
{
  LightBus.Begin(57600);
}

void loop()
{
  LightBus.Update();
  delay(25);
}

void LightBusSlave::Function0(byte data){
}
void LightBusSlave::Function1(byte data){
}
void LightBusSlave::Function2(byte data){
}
void LightBusSlave::Function3(byte data){
}
void LightBusSlave::Function4(byte data){
}
void LightBusSlave::Function5(byte data){
}
void LightBusSlave::Function6(byte data){
}
void LightBusSlave::Function7(byte data){
}
void LightBusSlave::Function8(byte data){
}
void LightBusSlave::Function9(byte data){
}
void LightBusSlave::Function10(byte data){
}
void LightBusSlave::Function11(byte data){
}
void LightBusSlave::Function12(byte data){
}
void LightBusSlave::Function13(byte data){
}
void LightBusSlave::Function14(byte data){
}
void LightBusSlave::Function15(byte data){
}
