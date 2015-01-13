//#import "Drawable.h"
#import "DrawableButton.h"
#import <TVout.h>
#import "Arduino.h"

DrawableButton::DrawableButton(){}

DrawableButton::DrawableButton(TVout& tv, unsigned int x, unsigned int y, unsigned int w, unsigned int h, char* title) {
	_tv = tv;
	_x = x;
	_y = y;
	_w = w;
	_h = h;
	_title = title;
	_tv.println("button: new");
	delay(1000);
}

// when setting a button, we black out, set the new title and call draw again
void DrawableButton::set(char* title) {
	_tv.draw_rect(_x, _y, _w, _h, WHITE, BLACK);
	_title = title;
	draw(_tv);
}

void DrawableButton::draw(TVout tv) 
{
	tv.print(_x+2,_y+2,_title);
	tv.draw_rect(_x, _y, _w, _h, WHITE);
}

void DrawableButton::toggle()
{
	_tv.draw_rect(_x, _y, _w, _h, WHITE, INVERT);
}
