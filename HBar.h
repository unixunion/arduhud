/*
  horizontal bar and arrow
*/

#ifndef HBar_h
#define HBar_h

#include "Arduino.h"
#include <TVout.h>
#include "Drawable.h"

class HBar : public Drawable
{
  public:
    HBar();
    HBar(TVout& tv, int x, int y, int length);
    virtual void set(int value);
    virtual void draw();
    int getValue();
    void setValue(int value);
    int getX();
    int getY();
    void test();

  protected:
    int _value;
    int _lastvalue;
    int _length;
    boolean _new;
    int _text_offset;
    int _range;
};

#endif
