
/* ledclose.c - Flow of Program - if device is not open then return SYSERR
                                  LED is not illuminated
                                  device not open
*/

#include <xinu.h>

extern struct LED led;

devcall	ledclose (
	  struct dentry	*devptr		/* entry in device switch table	*/
	)

{
   
      if (led.status != LED_OPEN) {
         return SYSERR;
      }       

      led.illuminated = LED_OFF;
      vGalileoBlinkLEDUsingLegacyGPIO(0); 
      led.status = LED_CLOSE;

      return OK;

}



