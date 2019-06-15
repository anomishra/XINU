
/* ledwrite.c - Flow of Program - if device is not open then return SYSERR
                                 if read or write more than 1 char then return SYSERR
*/

#include <xinu.h>

extern struct LED led;

devcall	ledwrite(
	  struct dentry	*devptr,	/* Entry in device switch table	*/
	  char	*buff,			/* Buffer of characters		*/
	  int32	count 			/* Count of character to write	*/
	)

{

       if (led.status == LED_CLOSE) {
          return SYSERR;
       }
     
       if (count != 1) {
          return SYSERR;
       }


       
       if ( *buff == LED_ON ) {
          vGalileoBlinkLEDUsingLegacyGPIO(1);
       }
       
       

