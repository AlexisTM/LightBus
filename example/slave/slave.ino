#include "LightBusSlave.h"
/*

RAPPEL POINTEURS : 
http://www.cplusplus.com/doc/tutorial/pointers/
& is the address-of operator, and can be read simply as "address of"se
* is the dereference operator, and can be read as "value pointed to by"

*/

enum STATES {
  IDLE,
  LOOP,
  ONEMORETIME
};

enum FUNCTIONS {
  NONE,
  FUNCTION0,
  FUNCTION1,
  FUNCTION2,
  FUNCTION3,
  FUNCTION4,
  FUNCTION5,
  FUNCTION6,
  FUNCTION7,
  FUNCTION8,
  FUNCTION9,
  FUNCTION10,
  FUNCTION11,
  FUNCTION12,
  FUNCTION13,
  FUNCTION14,
  FUNCTION15
};

// Default functions
byte dataBuffer;
FUNCTIONS function_todo = NONE;
STATES state = IDLE;

LightBusSlave LightBus;

void setup()
{
  LightBus.Begin(57600, 2);
  pinMode(13,OUTPUT);
}

void loop()
{
  switch(state){
  case IDLE:
    break;
  case LOOP:
    JobIt();
    break;
  case ONEMORETIME:
    JobIt();
    state = IDLE;
    break;
  default:
    state = IDLE;
    function_todo = NONE;
    break;
  }
  LightBus.Update();
  delay(25);
}

void JobIt(){
  /*switch(function_todo){
  case NONE:
    break;
  case FUNCTION2:
    LightBusSlave::Function2(dataBuffer);
    break;
  }*/
}

void LightBusSlave::Function0(byte data){
  digitalWrite(13, HIGH);
  state = IDLE;
}
void LightBusSlave::Function1(byte data){
  digitalWrite(13, LOW);
  state = IDLE;
}
void LightBusSlave::Function2(byte data){
 /* digitalWrite(13, HIGH};
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
  function_todo = FUNCTION2
  dataBuffer = data;
  state = LOOP;*/
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
