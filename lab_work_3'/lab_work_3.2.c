#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
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
    printf("i'm a parent process Thanks for your attention \n");
    return 0;
}