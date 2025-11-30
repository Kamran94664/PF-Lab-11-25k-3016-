#include <stdio.h>
#include <string.h>

int main()
{
    char list[5][20] = {"apple", "banana", "cat", "dog", "mango"};
    char input[20];
    int i;
    int found = 0;

    printf("Enter a word to search: ");
    scanf("%s", input);

    for (i = 0; i < 5; i++)
    {
        if (strcmp(list[i], input) == 0)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}
