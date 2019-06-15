

/* ledputc.c - Flow of Program - two arguments: device identification and single character
                                 if device is close or char is not Y||N return SYSERR
                                 LED state on or off
                                  
*/

#include <xinu.h>

extern struct LED led;

devcall	ledputc(
	struct	dentry	*devptr,	 /* Entry in device switch table */
	char	ch			/* Character to write		*/
	)
{
 
   if(led.status == LED_CLOSE) {
   return SYSERR;
   }

   if (ch == LED_OFF) {
   vGalileoBlinkLEDUsingLegacyGPIO(0);
   else if (ch == LED_ON) {
   vGalileoBlinkLEDUsingLegacyGPIO(1);
   } 
   else {
   return SYSERR;
   }

   led.illuminated = ch;
   return OK;

}

