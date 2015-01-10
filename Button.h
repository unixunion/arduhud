/*
  drawable button header
*/

#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include <TVout.h>

class Button
{
  public:
   Button();
   Button(TVout tv, int x, int y, int w, int h, char* title);
   void toggle();
   void update();
   void draw();
  private:
   TVout PROGMEM _tv;
   int _x;
   int _y;
   int _w;
   int _h;
};

#endif
