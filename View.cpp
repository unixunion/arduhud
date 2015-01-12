/* 
 View library for tv out
*/

#include "Arduino.h"
#include "View.h"
#include <TVout.h>
#include <fontALL.h>

#include "Button.h"
#include "HBar.h"

View::View() {
  Button btns[8];
  HBar hbars[4];
}

View::View(TVout& tv) {
   _tv = tv;
}

void View::add(Button& b) {
   view[viewId];
  
}

void ViewController::test() {
  Serial.println("testing views...");
  Button b1 = Button(_tv, 10, 10, 20, 9, "rcs");
}

