/* 
 Hbar library for horizontal bar with tvout
*/

#include "Arduino.h"
#include "HBar.h"
#include <fontALL.h>

HBar::HBar() {
}

HBar::HBar(TVout tv, int x, int y, int length)
{
  // some saves for later
  _new = true; // im new! ignore clear last position
  _x = x;
  _y = y;
  // select a small font
  _tv = tv;
  _tv.select_font(font4x6);
  _text_offset = -12;
  _length = length;
  _range = 65535/_length;
  
  // force first line to be long one
  bool firstline = true;
  int offset = 2; // first, middle and last line we want to set this 
  
  for (int counter = 0; counter <= length; counter++) {         
   // set length of line
   int l = 0;
  
   // if % 5, lengthen line
   if (counter % 5 == 0 || firstline ) {
    l = 3;

    // set 0 for no char
    int chr = 0;
    
    // determine if a char should be printer
    if (firstline) {
      chr=45; // -
    } else if (counter == length) { 
      chr=42; // +
    }
    
    if (chr != 0) {
      tv.print_char(x+counter-3, y+l+2, chr);
    }
      firstline = false;
   }
    
   if (counter == (length/2)) {
      offset = 2;
   } else if ( counter == length) {
      offset = 2; 
   }
    
   // draw the line at the desired length
   tv.draw_line( x+counter, y-offset, x+counter, y+l, WHITE );
   offset=0;
   
   // increment the pixel counter
   counter++;
 }
}

// sets the current target value which will be updated to in delta time
void HBar::setValue(int value) {
 _value = value; 
  
}

void HBar::update(int value) {
  
  
  // some if new overrides to avoid bit flipping some of the pixels before we have even started.
  if ( ! _new ) {
    //_tv.draw_circle((_x+((_lastvalue+32768)/_range))-2, _y, 3, INVERT );
    _tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y-2, INVERT );
    _tv.draw_line(_x+((_lastvalue+32768)/_range)-1, _y-3, _x+((_lastvalue+32768)/_range)+2, _y-3, INVERT);

    //_tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y-3, INVERT );
    //_tv.set_pixel((_x+((_lastvalue+32768)/_range))-1, _y-3, INVERT );
    //_tv.set_pixel((_x+((_lastvalue+32768)/_range))+1, _y-3, INVERT );
    
    _tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y+2, INVERT );
    //_tv.draw_line(_x+(lv/_range)-1, _y+3, _x+(lv/_range)+1, _y+3, INVERT);
    _tv.draw_line(_x+((_lastvalue+32768)/_range)-1, _y+3, _x+((_lastvalue+32768)/_range)+2, _y+3, INVERT);

    //_tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y+3, INVERT );
    //_tv.set_pixel((_x+((_lastvalue+32768)/_range))-1, _y+3, INVERT );
    //_tv.set_pixel((_x+((_lastvalue+32768)/_range))+1, _y+3, INVERT );
  } else {
    _new = false;
  };
  
  // clamping val
  _lastvalue = value;
  if (_lastvalue < -32768) {
    _lastvalue = -32768;
  } else if (_lastvalue > 32767) {
    _lastvalue = 32767;
  }
 
 // plot the last value after clamping has occured

  //_tv.draw_circle((_x+((_lastvalue+32768)/_range))-2, _y, 3, INVERT );
  _tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y-2, INVERT );
  _tv.draw_line(_x+((_lastvalue+32768)/_range)-1, _y-3, _x+((_lastvalue+32768)/_range)+2, _y-3, INVERT);
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y-3, INVERT );
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range))-1, _y-3, INVERT );
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range))+1, _y-3, INVERT );
  
  _tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y+2, INVERT );
  _tv.draw_line(_x+((_lastvalue+32768)/_range)-1, _y+3, _x+((_lastvalue+32768)/_range)+2, _y+3, INVERT);
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range)), _y+3, INVERT );
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range))-1, _y+3, INVERT );
  //_tv.set_pixel((_x+((_lastvalue+32768)/_range))+1, _y+3, INVERT );
  
 // clear the print area.
 _tv.draw_rect(_x + (_length/2)+(_text_offset), _y+5, 24, 5 ,BLACK, BLACK);
 
 // always force in positive signage too!
 String repr = String(_lastvalue);
 if (!repr.startsWith("-")) {
  repr = String("+") + repr;
 }
 
 // convert the string back to char array for TV
 char charBuf[8];
 repr.toCharArray(charBuf, 8);
  
 _tv.print(_x + (_length/2)+(_text_offset), _y+5, charBuf);
 //delay(2000); 
}

int HBar::getValue() {
  return _lastvalue;
}

int HBar::getX() {
  return _x;
}

int HBar::getY() {
  return _y;
}

void HBar::test() {
  
  // show that we are testing
  _tv.print(2, 2, "test");
  
  for (long v = -32768; v <= 32767; v=v+128) {
    update(v);
    delay(50);
    if (v==0) {
      delay(1000);
    }
  }
 
 delay(1000);
 // clear TEST text 
 _tv.draw_rect(2, 2, 16, 4 ,BLACK, BLACK);
  
}

