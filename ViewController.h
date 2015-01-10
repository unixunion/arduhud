/*
  multiple view controller
*/

#ifndef ViewController_h
#define ViewController_h

#include "Arduino.h"
#include <TVout.h>

class ViewController
{
  public:
   ViewController();
   ViewController(TVout tv);
   void changeView(int viewId);
   void draw();
   void test();

  private:
    TVout _tv;
};

template< typename _Type, size_t _Len > 
  class MPLArray{
    public:
      enum{ 
        Length 	= _Len,
        Size 	= sizeof( _Type ) * _Len,
      };
      _Type& operator[]( uint16_t i_Index ) { return this->t_Data[ i_Index ]; }
      operator _Type*(){ return this->t_Data; }
				
      _Type t_Data[ Length ];
};
#endif
