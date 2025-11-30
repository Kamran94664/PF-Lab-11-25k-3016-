#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("data.txt", "w");
    fclose(fp);

    fp = fopen("data.txt", "r");

    char ch = fgetc(fp);

    if (ch == EOF)
    {
        printf("File is empty.\n");
    }
    else
    {
        printf("File not empty.\n");
    }

    fclose(fp);

    return 0;
}
