/* 
 View library for tv out
*/

#include "Arduino.h"
#include "View.h"
#include <TVout.h>
#include <fontALL.h>

#include "Drawable.h"

View::View() {
	_currentObjects = 0;
}

View::View(TVout& tv) {
   _tv = tv;
}

void View::add(Drawable drawableObject) {
   viewContents[_currentObjects] = drawableObject;
}


