#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
    time_t rawtime;
    struct tm *pTime;

    printf("DIGITAL CLOCK\n");

    while (true)
    {
        time(&rawtime);
        pTime = localtime(&rawtime);

        int hour = pTime->tm_hour;
        const char *period = "AM";

        if (hour == 0) {
            hour = 12;
        } else if (hour == 12) {
            period = "PM";
        } else if (hour > 12) {
            hour -= 12;
            period = "PM";
        }

        printf("\r%02d:%02d:%02d %s",
               hour,
               pTime->tm_min,
               pTime->tm_sec,
               period);

        fflush(stdout);
        sleep(1);
    }
}

