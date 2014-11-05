#include "LightBusMaster.h"

LightBusMaster::LightBusMaster(){
}

void LightBusMaster::Begin(int baudrate)
{
  Serial.begin(57600);
}

// Code the data to 
// 1 ADR(3) FUNC(4) |  0 DATA(7)
// 128 : 			10000000 OR
// adr(3) >> 4 : 	0XXX0000 OR
// function : 		0000YYYY =
// adrfunc = 		1XXXYYYY
void LightBusMaster::Send(byte adress, byte function, byte data)
{
  byte adrfunc;
  if(adress > 7) adress = 7;
  if(function > 15) function = 15;
  if(data > 127) data = 127;
  adrfunc = ( 128 ) | (adress >> 4) | (function);
  OutBuffer[0] = adrfunc;
  OutBuffer[1] = data;
  Serial.write(OutBuffer, 2);
}

