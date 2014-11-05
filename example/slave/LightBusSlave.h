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

    1 adr(3) func(4)| 0 data(7)|
*/

#include "Arduino.h"
#include "HardwareSerial.h"

#ifndef LightBusSlave_h
#define LightBusSlave_h
// MACROS
// Get the 3 most significants bits
// 0x38 = 01110000
#define ADRESS(ww) (byte)((ww & 0x38) >> 4)
// Get the 4 least significants bits
#define FUNCTION(ww) (byte)((ww & 0x0F))
#define DATA(ww) (byte)((ww & 0x7F))


class LightBusSlave
{
  public:
    LightBusSlave();
    void Update();
    byte TodoBuffer[2];
    byte OutBuffer[2];
    void Begin(int baudrate = 57600, byte adress = 1);
    byte MyAdress;
    void Send(byte adress, byte function, byte data = 0);
    void Function0(byte data) __attribute__((weak));
    void Function1(byte data) __attribute__((weak));
    void Function2(byte data) __attribute__((weak));
    void Function3(byte data) __attribute__((weak));
    void Function4(byte data) __attribute__((weak));
    void Function5(byte data) __attribute__((weak));
    void Function6(byte data) __attribute__((weak));
    void Function7(byte data) __attribute__((weak));
    void Function8(byte data) __attribute__((weak));
    void Function9(byte data) __attribute__((weak));
    void Function10(byte data) __attribute__((weak));
    void Function11(byte data) __attribute__((weak));
    void Function12(byte data) __attribute__((weak));
    void Function13(byte data) __attribute__((weak));
    void Function14(byte data) __attribute__((weak));
    void Function15(byte data) __attribute__((weak));
    
  private:
    inline boolean IsForMe(byte adress);  
    inline boolean IsSync(byte adrfunc);
    void WhatIsTheJob();

    
};

#endif
