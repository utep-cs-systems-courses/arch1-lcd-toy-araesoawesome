#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

short redrawScreen = 1;

void main(void)
{
  configureClocks();
  switch_init();
  //buzzer_init();
  //led_init();
  enableWDTInterrupts();

  or_sr(0x08);
  
  lcd_init();
  clearScreen(COLOR_DARK_OLIVE_GREEN);
    
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      drawString5x7(10,20, "The Legend of Zelda", COLOR_YELLOW, COLOR_DARK_OLIVE_GREEN);
      myShape(75,40,COLOR_YELLOW);
    }
    or_sr(0x10);  // CPU off
    }
}

void wdt_c_handler(){
  static short i = 0;
  i++;
  if(i ==125){
    //state_advance();
    i=0;
    redrawScreen = 1;
  }
}
