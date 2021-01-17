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
    int channelStatus = mkfifo("chanel", 0640);
    if(channelStatus == -1)
    {
        perror("we have some problems with opepning the channel");
        exit(1);
    }
    FILE *source = fopen("./textFile1.txt", O_RDONLY);
    if(source == NULL) 
    {
        perror("we have some problems with opepning the file");
        exit(1);
    }
    FILE * FIFOchannel = fopen("channel", "w+");
    if(FIFOchannel == NULL)
    {
        perror("we have some problems with reading the channel file");
        exit(1);
    }
    while(fgets(buffer, BUFFER_SIZE, source) != NULL) {
        printf("%s", buffer);
        fputs(buffer, FIFOchannel);
    }
    fclose(source);
    unlink ("chanel");
    return 0;
}