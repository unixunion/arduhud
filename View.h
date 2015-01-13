/*
  multiple view controller
*/

#ifndef View_h
#define View_h

#include "Arduino.h"
#include <TVout.h>
#include "Drawable.h"

const int NUMBER_ITEMS_PER_VIEW = 12;

class View
{
  public:
   View();
   View(TVout& tv);   
   void add(Drawable* drawableObject);
   int count();
   Drawable* viewContents[NUMBER_ITEMS_PER_VIEW];
   int _currentObjects;
  protected:
    TVout _tv;
    
};

#endif
