
/*

Be sure to put TVout dir in libraries! The default TVoutBeta1 name kind of messes with things if you just drop the zip in via IDE

*/

#include <TVout.h>
#include <fontALL.h>
#include "logo.h"
#include "HBar.h"
#include "ViewController.h"
#include "Button.h"
#include "MemoryFree.h"

static TVout TV;
TVout& TV_ptr = TV;

HBar hBar;
ViewController vc;

Button btns[8];

int test = -112;

void setup() {
  //Serial.begin(9600);

  TV.begin(NTSC,96,64);
  TV.select_font(font4x6);
  intro();
  //TV.clear_screen();
  
  TV.clear_screen();
 
  vc = ViewController(TV_ptr);

  //Serial.print(F("View Controller Test"));
  //vc.test();
  delay(1000);
   
  //Serial.println("b1");
  btns[0] = Button(TV_ptr, 0, 0, 31, 9, "  RCS");;
  //Serial.println("b2");
  btns[1] = Button(TV_ptr, 0, 12, 31, 9, "  SAS");
  //Serial.println("b3");
  btns[2] = Button(TV_ptr, 0, 24, 31, 9, " GEAR");
  //Serial.println("b4");
  btns[3] = Button(TV_ptr, 0, 36, 31, 9, " LIGHT");
  //Serial.println("b5");
  btns[4] = Button(TV_ptr, TV.hres()-36, 36, 31, 9, " BRAKE");

  hBar = HBar(TV_ptr,(TV_ptr.hres()-80)/2,TV_ptr.vres()-12,80);
  
  TV.select_font(font8x8);
  TV.print(TV.hres()-48, 1, "RAM:");
  TV.select_font(font4x6);
  
  // test the buttons
  for (int i = 0; i<=4; i++) {
    btns[i].toggle();
    delay(250); 
  }
  
  for (int i = 0; i<=4; i++) {
    btns[i].toggle();
    delay(250); 
  }
  
  for (int i = -32768; i<=32766; i++) {
    if (i%128==0) {
      hBar.update(i);
    } 
  }

 

btns[1].toggle();
//rcsbutton.toggle();
  
  //TV.draw_rect(0,0,TV.hres()-1,TV.vres()-1,WHITE);
  
  //hBar.test();
  //delay(1000);
  
  //TV.delay(2500);
  //TV.clear_screen();
  
  //rectangles and lines
  //TV.draw_rect(20,20,80,56,WHITE);
  //TV.delay(500);
  //TV.draw_rect(10,10,100,76,WHITE,INVERT);
  //TV.delay(500);
  //TV.draw_line(60,20,60,76,INVERT);
  //TV.draw_line(20,48,100,48,INVERT);
  //TV.delay(500);
  //TV.draw_line(10,10,110,86,INVERT);
  //TV.draw_line(10,86,110,10,INVERT);
  //TV.delay(2000);
    
  //randomSeed(analogRead(0));
}


void loop() {

  if (hBar.getValue()+(test)>=32767 || hBar.getValue()+(test)<=-32768) {
    test=test*-1;
  }
  
  hBar.update(hBar.getValue()+(test));
  
  delay(50);
  TV.draw_rect(TV.hres()-22, 1, 20, 6, BLACK);
  TV.print(TV.hres()-22, 1, freeMemory());
  
  //Serial.print("freeMemory()=");
  //Serial.println(freeMemory());
  
}

void intro() {
unsigned char w,l,wb;
  int index;
  w = pgm_read_byte(Logo);
  l = pgm_read_byte(Logo+1);
  if (w&7)
    wb = w/8 + 1;
  else
    wb = w/8;
  index = wb*(l-1) + 2;
  for ( unsigned char i = 1; i < l; i++ ) {
    TV.bitmap((TV.hres() - w)/2,0,Logo,index,w,i);
    index-= wb;
    TV.delay(50);
  }
  for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
    TV.bitmap((TV.hres() - w)/2,i,Logo);
    TV.delay(50);
  }
  TV.delay(3000);
  TV.clear_screen();
}


