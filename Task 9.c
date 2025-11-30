#include <stdio.h>

int recursiveSearch(int arr[], int size, int target, int index)
{
    if (index >= size)
    {
        return -1;
    }

    if (arr[index] == target)
    {
        return index;
    }

    return recursiveSearch(arr, size, target, index + 1);
}

int main()
{
    int numbers[10];
    int i;
    int target;
    int found;

    printf("Enter 10 numbers:\n");
    for (i= 0; i< 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &target);

    found = recursiveSearch(numbers, 10, target, 0);

    if (found == -1)
    {
        printf("Target not found.\n");
    }
    else
    {
        printf("Target found at index %d.\n", found);
    }

    return 0;
}
