#include <stdio.h>
#include <string.h>

void reverse(char str[], int s, int e) {
    if (s >= e) {
        return;
    }

    char temp = str[s];
    str[s] = str[e];
    str[e] = temp;

    reverse(str, s + 1, e - 1);
}

int main() {
    char str[50];
    printf("Enter The word: ");
    fgets(str, 50, stdin);

    str[strcspn(str, "\n")] = '\0';

    int len = strlen(str);

    reverse(str, 0, len - 1);

    printf("Reversed: %s\n", str);
    return 0;
}

