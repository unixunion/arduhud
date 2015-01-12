#include "Arduino.h"
#include "Drawable.h"
#include "Button.h"
#include <fontALL.h>
#include <TVout.h>


Button::Button() {
  
}

Button::Button(TVout& tv, unsigned int x, unsigned int y, unsigned int w, unsigned int h, char* title) {
  
//  Serial.println("Creating button");
//  Serial.print("size of title: " );
//  Serial.println(sizeof(title));
  
  _tv = tv;
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  
  _tv.print(x+2,y+2,title);
  _tv.draw_rect(x, y, w, h, WHITE);
  
}

void Button::toggle() {
  _tv.draw_rect(_x, _y, _w, _h, WHITE, INVERT);
}

