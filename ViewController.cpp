/* 
 ViewController library for tv out
*/

#include "Arduino.h"
#include "ViewController.h"
#include <TVout.h>
#include <fontALL.h>
#include "View.h"
#include "Drawable.h"

ViewController::ViewController() {
	currentView = 0;
}

// Initialize the view and the Tvout object
ViewController::ViewController(TVout& tv) {
   _tv = tv;
}

// add a drawable to the view
void ViewController::add(Drawable& drawableObject, int viewId) {
   views[viewId].add(drawableObject);
}

void ViewController::changeView(int viewId) {
	_tv.clear_screen();
	// for drawable in view[index] call .draw();
	for (int x=0; x<NUMBER_ITEMS_PER_VIEW; x++) {
		View v = views[viewId];
		Drawable d;
		d = v.viewContents[x];
		d.draw();
		//d->draw();
		//Drawable d =  d.draw();
	}
}

