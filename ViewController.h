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
   void draw();
   void add(Drawable& drawableObject, int viewId);
  protected:
    int currentView; // the current view id
    View views[3]; // 4 views
    TVout _tv;
};

#endif
