

/* ledgetc.c - Flow of Program - if device is not open then return SYSERR
                                 LED is illuminated then return 'Y'
                                 LED is deilluminated then return illuminated or 'N'
                                  
*/

#include <xinu.h>

extern struct LED led;

devcall	ledgetc(
	  struct dentry	*devptr,		/* Entry in device switch table	*/
          char c
	)

{
       if (led.status == LED_CLOSE) {
         return SYSERR;
       }       

       else if (led.illuminated == LED_ON) {
         return  'Y';
       }
      
       else (led.illuminated == LED_OFF) {
         return 'N';
       }
}