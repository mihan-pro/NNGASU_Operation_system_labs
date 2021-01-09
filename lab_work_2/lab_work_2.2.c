#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main()
{
    char buffer[BUFFER_SIZE];
    FILE* file1 = fopen("./textFile1.txt", "r");
    if (file1 == NULL)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    FILE* file2 = fopen("./textFile2.txt", "w");
    if (file2 == NULL)
    {
        perror("We have some problem with opening a file");
        exit(1);
    }
    while(fgets(buffer, BUFFER_SIZE, file1) != NULL) {
        fputs(buffer, file2);
    }
    fclose(file1);
    fclose(file2);
    return 0;
}