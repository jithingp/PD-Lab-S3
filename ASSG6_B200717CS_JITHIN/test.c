#include <stdio.h>
int main()
{
    char name[50];
    int marks, i, num;
    printf("Enter number of students: ");
    scanf("%d", &num);
    FILE *fptr;
    fptr = fopen("student3.txt", "w");
    if (fptr == NULL)
    {
        perror("Error!");
        return 1;
    }
    for (i = 0; i < num; ++i)
    {
        printf("For student%d\nEnter the name: ", i + 1);
        scanf("%s", name);
        printf("Enter marks: ");
        scanf("%d", &marks);
        fprintf(fptr, "Name: %s\tMarks=%d \n", name, marks);
    }
    fclose(fptr);
}