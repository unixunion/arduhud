/*
  horizontal bar and arrow
*/

#ifndef HBar_h
#define HBar_h

#include "Arduino.h"
#include <TVout.h>

class HBar
{
  public:
    HBar();
    HBar(TVout tv, int x, int y, int length);
    void update(int value);
    int getValue();
    int getX();
    int getY();
    void test();
    void setValue(int value);

  private:
    void draw();
    int _value;
    int _lastvalue;
    int _x;
    int _y;
    TVout PROGMEM _tv;
    int _length;
    boolean _new;
    int _text_offset;
    int _range;
};

#endif
