#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 256+1

int main() {
    char buffer[BUFFER_SIZE];
    int file = open("textFile.txt", O_RDONLY);
    if(file < 0) 
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    while(read(file, buffer, BUFFER_SIZE-1) > 0) {
        buffer[BUFFER_SIZE] = "\0";
        printf("%s", buffer);
    } 
    printf("\n");
    int isClosedFile = close(file);
    if(isClosedFile != 0) {
        perror("We have some problem with closing a file");
        exit(1);
    }
    return 0;
}