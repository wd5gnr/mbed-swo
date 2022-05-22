/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "SWO.h"



// Blinking rate in milliseconds
std::chrono::milliseconds rate=150ms;








DigitalOut led(LED1);

const char *color[]={ "#GRN#", "#RED#", "#ORG#" };

SWO_Channel debugport;
SWO_Channel dbg2("X",1);
SWO_Channel leddbg("LED",5);
  int main() 
  {
      unsigned count=0;
      debugport.printf("\r\nHello World from SWO\r\n");
      debugport.printf("CPU SystemCoreClock is %d Hz\r\n", SystemCoreClock);
  
    while(1) {
      led = !led;   // flip LED if output is true
      
        ThisThread::sleep_for(rate);  // sleepy time
    
      if (count % 10) debugport.putc('*'); else debugport.printf("%s%d\r\n",color[(count/10)%3],count); 
      dbg2.printf("\r\nCount=%d",count);
      leddbg.printf("\r\nState of LED=%d",led.read());
      count++;
    }
  }
    


