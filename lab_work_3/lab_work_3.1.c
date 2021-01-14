#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i = 0;
    time_t startTime = time(NULL);
    while(i++ < 10000)
    {
        int result = system("./../lab_work_2/lw2.2");
    }
    time_t endTime =  time(NULL);
    printf("%ld", (endTime - startTime));
    printf("\n i'm a parent process Thanks for your attention \n");
    return 0;
}

/*
    It takes 18 seconds to execute this code inside while loop.
*/