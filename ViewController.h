/*
  multiple view controller
*/

#ifndef ViewController_h
#define ViewController_h

#include "Arduino.h"
#include <TVout.h>
#include "View.h"

class ViewController
{
  public:
   ViewController();
   ViewController(TVout& tv);
   void changeView(int viewId);
   void addView(View *view);
   void draw();
   void add(Drawable *drawableObject, int viewId);
   View* views[3]; // 4 views 
   TVout _tv;
    int currentView; // the current view id
    
};

#endif
