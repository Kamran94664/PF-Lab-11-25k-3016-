#include <stdio.h>
#include <string.h>

int isPalindrome(char word[])
{
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right)
    {
        if (word[left] != word[right])
        {
            return 0;
        }

        left = left + 1;
        right = right - 1;
    }

    return 1;
}

int main()
{
    char words[5][20];
    int i;

    printf("Enter 5 words:\n");

    for (i = 0; i < 5; i++)
    {
        scanf("%s", words[i]);
    }

    for (i = 0; i < 5; i++)
    {
        if (isPalindrome(words[i]) == 1)
        {
            printf("%s -> Palindrome\n", words[i]);
        }
        else
        {
            printf("%s -> Not Palindrome\n", words[i]);
        }
    }

    return 0;
}
