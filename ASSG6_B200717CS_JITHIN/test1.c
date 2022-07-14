#include <stdlib.h> // For exit()
#include <stdio.h>
int main()
{
    FILE *fptr;
    char filename[100], c;
    printf("Enter the filename to open \n");
    scanf("%s", filename);
    fptr = fopen(filename, "r"); // Open file in read mode
    if (fptr == NULL)
    { //if file does not exist
        perror("Cannot open file \n");
        exit(0);
    }
    c = fgetc(fptr); // Gets the next character from the file
    while (c != EOF)
    { //while loop is executed until EOF (End of File) is reached
        printf("%c", c);
        c = fgetc(fptr);
    }
}