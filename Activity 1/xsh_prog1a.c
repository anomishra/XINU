
#include<xinu.h>
#include<stdlib.h>

shellcmd xsh_prog1a(int nargs, char *args[])
{
    int i;
    if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) 
    {
        printf("Use: %s\n\n", args[0]);
        printf("Description:\n");
        printf("\tDisplays message equivalent to number passed as a parameter\n");
        printf("Options:\n");
        printf("\t--help\t display this help and exit\n");
        return 0;
    }

    if(nargs==2)
    {
        int n=atoi(args[1]);

        if(n<0)
        {
            printf("Argument passed is a negative number.");
            return SYSERR;
        }
        else
        {

            for(i=1;i<=n;i++)
            {
                sleepms(1500);
                printf("prog1a message %d\n",i);

            }
        }
    }
    else
    {
        printf("Inappropriate number of arguments");
        return SYSERR;
    }

    return 0;
} 
