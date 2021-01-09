#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char symbol;
    int file1 = open("textFile1.txt", O_RDONLY);
    if (file1 < 0)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    int file2 = open("textFile2.txt", O_WRONLY);
    if (file2 < 0)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    while(read(file1, &symbol, 1) > 0) {
        write(file2, &symbol, 1);
    }
    close(file1);
    close(file2);
    return 0;
}