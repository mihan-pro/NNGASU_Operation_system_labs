#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int i = 0;
    time_t startTime = time(NULL);
    while(i++ < 10000)
    {
        pid_t result = fork();
        if (result == -1)
        {
            perror("we couldn't start new process");
            exit(1);
        }
        else if(result == 0) 
        {
            char* args[] = {"lw2.2", NULL};
            execv("./../lab_work_2/lw2.2", args);
        } 
    }
    time_t endTime =  time(NULL);
    printf("%ld", (endTime - startTime));
    printf("\n i'm a parent process Thanks for your attention \n");
    return 0;
}

/*
    It takes 1-2 seconds to execute this code inside while loop.
*/