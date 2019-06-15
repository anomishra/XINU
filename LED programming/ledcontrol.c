

/* ledcontrol.c - Flow of Program - control will always return default
                                 
*/

#include <xinu.h>

extern struct LED led;

devcall	ledcontrol(
	struct	dentry	*devptr,	        /* Entry in device switch table	*/
	char	*buff			/* Buffer of characters		*/
               )
{      
	return (devcall)SYSERR;
}
   

