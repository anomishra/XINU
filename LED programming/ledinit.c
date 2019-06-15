
/* ledinit.c - Flow of program: Initialise the hardware functions */


#include <xinu.h>

struct LED led;
devcall ledinit(
	  struct dentry	*devptr		/* Entry in device switch table	*/
	)
{
    
    /*--------------------------*/
    /* Initialize the hardware. */
    /*--------------------------*/

    vGalileoInitializeGpioController();
    vGalileoInitializeLegacyGPIO();
    vGalileoLegacyGPIOInitializationForLED();

    led.status = LED_CLOSE;
    led.illuminated = LED_OFF;
    return OK;
}
