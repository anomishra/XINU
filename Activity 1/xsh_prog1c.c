
#include<xinu.h>
#include<stdlib.h>

void prog1a(int);
void prog1b(int);

shellcmd xsh_prog1c(int nargs, char *args[])
{
   
    int na,nb,pa,pb,time;
    pid32 p1;
    pid32 p2;

    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) 
    {
        printf("Use: %s\n\n", args[0]);
        printf("Description:\n");
        printf("\tDisplays message from two processes accrding to the arguments passed\n");
        printf("Options:\n");
        printf("\t--help\t display this help and exit\n");
        return 0;
    }


    if(nargs==5)
    {
        na = atoi(args[1]);
        pa = atoi(args[2]);
        nb = atoi(args[3]);
        pb = atoi(args[4]);

        if(na>0 && nb>0 && pa>0 && pb>0)
        {

                p1 = (create(prog1a, 8192, pa, "process1", 1, na));
                p2 = (create(prog1b, 8192, pb, "process2", 1, nb));

                if(p1 != SYSERR)
            {
                resume(p1);
            }
            else
            {
                printf("\nERROR: Process prog1a creation was unsuccessful!\n");
            }
            
            if(p2 != SYSERR)
            {
                resume(p2);
            }
            else
            {
                printf("\nERROR: Process prog1b creation was unsuccessful!\n");
            }
        }
        else
        {
            printf("Arguments passed are a negative numbers.");
            return SYSERR;
        }

    }
    else
    {
        printf("Inappropriate number of arguments");
        return SYSERR;
    }
    
    
    time = ((na*1500)+(nb*2500)+1000);
    sleepms(time);    
    return 0;
} 


void prog1a(int n)
{
   int i;
    for(i=1;i<=n;i++)
    {
        sleepms(1500);
        printf("prog1a message %d\n",i);
    }
}


void prog1b(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        sleepms(2500);
        printf("prog1b message %d\n",i);

    }

}
