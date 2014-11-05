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
  LightBus.Send(2,0);
  delay(500);
  LightBus.Send(2,1);
  delay(500);
}
