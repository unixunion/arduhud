/*
  drawable button header
*/

#ifndef Button_h
#define Button_h

#include <TVout.h>


class Button
{
  public:
   Button();
   Button(TVout& tv, unsigned int x, unsigned int y, unsigned int w, unsigned int h, char* title);
   void set(char* value);
   void toggle();
   void draw();
  private:
   TVout _tv;
   unsigned int _x;
   unsigned int _y;
   unsigned int _w;
   unsigned int _h;
};

#endif
