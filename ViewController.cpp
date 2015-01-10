/* 
 ViewController library for tv out
*/

#include "Arduino.h"
#include "ViewController.h"
#include <TVout.h>
#include <fontALL.h>

#include "Button.h"

ViewController::ViewController() {
  
}

ViewController::ViewController(TVout tv) {
   MPLArray< uint8_t, 4 > view_Array = { 'a', 'b', 'c', '\0' };
   _tv = tv;
}

void ViewController::test() {
  Serial.println("testing views...");
  Button b1 = Button(_tv, 10, 10, 20, 9, "rcs");
}

