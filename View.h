/*
  multiple view controller
*/

#ifndef View_h
#define View_h

#include "Arduino.h"
#include <TVout.h>
#include "Button.h"
#include "HBar.h"

class View
{
  public:
   View();
   View(TVout& tv);   
   void add(Button& button);
   void add(HBar& hBar);

  private:
    TVout _tv;
};

#endif
