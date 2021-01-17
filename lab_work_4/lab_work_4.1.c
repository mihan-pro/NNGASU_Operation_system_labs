#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *startCopying(void *arguments)
{
    int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];
    FILE *file1 = fopen("/home/mike/NNGASU_Operation_system_labs/lab_work_2/textFile1.txt", "r");
    if (file1 == NULL)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    FILE *file2 = fopen("/home/mike/NNGASU_Operation_system_labs/lab_work_2/textFile2.txt", "w");
    if (file2 == NULL)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    while (fgets(buffer, BUFFER_SIZE, file1) != NULL)
    {
        fputs(buffer, file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}

int main(void)
{
    int i = 0;
    time_t startTime = time(NULL);
    pthread_t thread;
    while (i++ < 10000)
    {
        int result = pthread_create(&thread, NULL, &startCopying, NULL);
        if (result != 0)
        {
            perror("we have an error in creating thread process \n");
        }
        result = pthread_join(thread, NULL);
        if (result != 0)
        {
            perror("we have an error in waiting for the finish of thread process \n");
        }
    }
    time_t endTime = time(NULL);
    printf("%ld", (endTime - startTime));
    printf("\n i'm a parent process Thanks for your attention \n");
    return 0;
}

/*
    It takes 3 seconds to execute this code inside while loop.
*/