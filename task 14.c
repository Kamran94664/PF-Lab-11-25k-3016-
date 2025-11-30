#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fp;
    time_t currentTime;
    struct tm *timeInfo;

    fp = fopen("log.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    currentTime = time(NULL);

    timeInfo = localtime(&currentTime);

    fprintf(fp, "Program executed at: %02d:%02d:%02d\n",
            timeInfo->tm_hour,
            timeInfo->tm_min,
            timeInfo->tm_sec);

    fclose(fp);

    printf("Timestamp saved to log.txt\n");

    return 0;
}
