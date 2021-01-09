#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main()
{
    char buffer[BUFFER_SIZE];
    FILE *file = fopen("textFile.txt", "r");
    if (file == NULL)
    {
        perror("we have some problem with opening file\n");
        exit(1);
    }
    while (fgets(buffer, BUFFER_SIZE, file))
    {
        printf("%s", buffer);
    }
    printf("\n");
    fclose(file);
    return 0;
}