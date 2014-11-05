/* 
  LightBusMaster.h : Master code for a lightbus on Arduino
  V-0.0.1 Copytight (C) 2014 Alexis Paques
  written and in test for Arduino Duo
  
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "Arduino.h"
#include "HardwareSerial.h"

#ifndef LightBusMaster_h
#define LightBusMaster_h
// MACROS
// Get the 4 most significants bits
#define ADRESS(ww) (byte)((ww & 0x38) >> 4)
// Get the 4 least significants bits
#define FUNCTION(ww) (byte)((ww & 0x0f))

class LightBusMaster
{
  public:
    LightBusMaster();
    byte TodoBuffer[2];
    byte OutBuffer[2];
    void Update();
    void Begin(int baudrate = 57600);
    byte MyAdress;
    void Send(byte adress, byte function, byte data = 0);
  private:
    inline boolean IsForMe(byte adress);  
};

#endif
