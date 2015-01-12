#include <font4x6.h>
#include <font6x8.h>
#include <font8x8.h>
#include <font8x8ext.h>
#include <fontALL.h>

#include <TVout.h>
#include <video_gen.h>

#include <Button.h>
#include <Drawable.h>
#include <DrawableButton.h>
#include <HBar.h>
#include <MemoryFree.h>
#include <View.h>
#include <ViewController.h>

ViewController vc;
DrawableButton button1;
DrawableButton button2;


static TVout TV;
TVout& TV_ptr = TV;

void setup() {
  TV.begin(NTSC,96,64);
  TV.select_font(font4x6);
  // put your setup code here, to run once:
  vc = ViewController();
  button1 = DrawableButton(TV_ptr, 1, 1, 10, 10, "Test2");
  button1 = DrawableButton(TV_ptr, 1, 1, 10, 10, "Test2");
  vc.add(button1, 0);
  vc.add(button2, 1);
  vc.changeView(1);


}

void loop() {
  // put your main code here, to run repeatedly:

}
