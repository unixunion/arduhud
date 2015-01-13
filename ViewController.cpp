/* 
 ViewController library for tv out
*/

#include "Arduino.h"
#include "ViewController.h"
#include <TVout.h>
//#include <fontALL.h>
#include "View.h"
#include "Drawable.h"

ViewController::ViewController() {
	currentView = 0;
}

// Initialize the view and the Tvout object
ViewController::ViewController(TVout& tv) {
   _tv = tv;
   _tv.println("VC: init...");
   // View v0 = View(_tv);
   // View v1 = View(_tv);
   // views[0] = &v0;
   // views[1] = &v1;
   delay(1000);
}

void ViewController::addView(View *view) {
	currentView++;
	views[currentView] = view;
}

// add a drawable to the view
void ViewController::add(Drawable *drawableObject, int viewId) {
	_tv.println("VC: add0");
	delay(1000);
   	views[viewId]->add(drawableObject);
}

void ViewController::changeView(int viewId) {
	// _tv.clear_screen();
	// for drawable in view[index] call .draw();
	int max = 1; //views[viewId]->count();
	_tv.clear_screen();
	_tv.println(max);
	delay(5000);
	for (int x=0; x<max; x++) {
		// View v = views[viewId];
		// Drawable d;
		// d = ;
		views[viewId]->viewContents[x]->draw(); 
	}
}

