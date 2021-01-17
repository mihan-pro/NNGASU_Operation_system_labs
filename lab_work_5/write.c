#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main ()
{
    char symbol;
    char buffer[BUFFER_SIZE];
    FILE *target = fopen("./textFile2.txt", "w+");
    if(target == NULL) 
    {
        perror("we have some problems with opepning the file");
        exit(1);
    }
    FILE * FIFOchannel = fopen("channel", "r");
    if(FIFOchannel == NULL)
    {
        perror("we have some problems with reading the channel file");
        exit(1);
    }
    while(fgets(buffer, BUFFER_SIZE, FIFOchannel) != NULL) {
        printf("%s",buffer);
        fputs(buffer, target);
    }
    fclose(target);
    return 0;
}