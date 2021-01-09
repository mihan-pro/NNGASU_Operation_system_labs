#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char symbol;
    int file = open("textFile.txt", O_RDONLY);
    if(file < 0) 
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    while(read(file, &symbol, 1) > 0) {
        printf("%c",symbol);
    }
    printf("\n");
    int isClosedFile = close(file);
    if(isClosedFile != 0) {
        perror("We have some problem with closing a file");
        exit(1);
    }
    return 0;
}