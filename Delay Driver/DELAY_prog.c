#include "DELAY_interface.h"

void Delay(unsigned long volatile time)
{
    //time = 145448;  // 0.1sec
    time *= (1454480 / 2);
    while(time)
    {
		  time--;
    }
}

void Delay_ms(unsigned long volatile time)
{
  time *= 1454.48;
  while(time)
  {
    time--;
  }
  
}



