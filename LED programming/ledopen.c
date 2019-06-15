
/* ledopen.c - Flow of Program - if device is not open then return SYSERR
                                  LED is not illuminated
                                  device not open
*/

#include <xinu.h>

extern struct LED led;

devcall	ledopen (
	 struct	dentry	*devptr,	/* Entry in device switch table	*/
	 char	*buff1,			
	 char	*buff2			
	)

{
   
      if (led.status == LED_OPEN) {
         return SYSERR;
      }   
      
	led.status = LED_OPEN;

	 vGalileoBlinkLEDUsingLegacyGPIO(0); 
	 led.illuminated = LED_OFF;

	return devptr->dvnum;
}