#include <TVout.h>
#include <fontALL.h>
#include "logo.h"
#include "HBar.h"

TVout TV;
HBar hBar;
int test = -112;

void setup() {
  Serial.begin(9600);

  Serial.print("Math Test");
  Serial.println(0 + (-1));

  TV.begin(NTSC,120,96);
  TV.select_font(font6x8);
  //intro();
  //TV.clear_screen();
  
  TV.clear_screen();
 
 
  hBar = HBar(TV,(TV.hres()-80)/2,TV.vres()-12,80);
  
  TV.draw_rect(0,0,TV.hres()-1,TV.vres()-1,WHITE);
  
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

  if (hBar.getValue()+(test)>=32768 || hBar.getValue()+(test)<=-32768) {
    test=test*-1;
    Serial.print("Test: ");
    Serial.println(test);
  }
  
  hBar.update(hBar.getValue()+(test));
  //hBar.update(0);
  
  //Serial.print("Value: ");
  //Serial.println(hBar.getValue());
  //Serial.println(hBar.getY());
  delay(50);
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


