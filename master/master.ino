#include "LightBusMaster.h"
/*

RAPPEL POINTEURS : 
http://www.cplusplus.com/doc/tutorial/pointers/
& is the address-of operator, and can be read simply as "address of"
* is the dereference operator, and can be read as "value pointed to by"

*/
// 5 bytes for data is the maximum!
LightBusMaster LightBus;

void setup()
{
  LightBus.Begin(57600);
}

void loop()
{
  // 
  // Send to slave 5, function 12, data 12
  LightBus.Send(5, 12, 12);
  // Send to slave 5, function 12 : Nothing, just do the function
  LightBus.Send(5, 12);
  delay(25);
}
