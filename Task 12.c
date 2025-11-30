#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int chars = 0;
    int words = 0;
    int lines = 0;

    fp = fopen("text.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        chars = chars + 1;

        if (ch == ' ' || ch == '\n')
        {
            words = words + 1;
        }

        if (ch == '\n')
        {
            lines = lines + 1;
        }
    }

    words = words + 1;

    fclose(fp);

    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);

    return 0;
}
