#ifndef DrawableButton_h
#define DrawableButton_h

#include <TVout.h>
#include "Drawable.h"

class DrawableButton : public Drawable 
{	
public:
	DrawableButton();
	DrawableButton(TVout& tv, unsigned int x, unsigned int y, unsigned int w, unsigned int h, char* title);
	void draw();
	void set(char* title);
	void toggle();
private:
	char* _title;
};

#endif