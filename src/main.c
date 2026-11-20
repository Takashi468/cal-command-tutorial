#include "day_mon.h"
#include <stdio.h>
#include <time.h>

void
time_check_os()
{
    time_t now = time(NULL);
    char c_time_buffer[26];
#if defined(_WIN32)
    if (ctime_s(c_time_buffer, sizeof(c_time_buffer), &now) == 0) {
        printf("OS: Windows\n");
        printf("%s", c_time_buffer);
    } else {
        printf("Error time\n");
    }
#elif defined(__linux__)
    ctime_r(&now, c_time_buffer);
    printf("OS: Linux\n");
    printf("%s", c_time_buffer);
#endif
}

int
calculate_day_1(int mon, int year)
{
    static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (mon < 3) {
        year -= 1;
    }
    int day_1 = (year + year / 4 - year / 100 + year / 400 + t[mon - 1] + 1) % 7;
    return day_1;
}

void
calendar_now()
{
    const char *nameMon[12]
        = { "January", "February", "March",     "April",   "May",      "June",
            "July",    "August",   "September", "October", "November", "December" };
    const char nameweeks[] = { "Su Mo Tu We Th Fr Sa" };
    struct tm t;
    time_t now = time(NULL);
    localtime_s(&t, &now);
    // printf("localtime_s %d", &t);
    // printf("localtime_s: %02d/%02d/%d \n", t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
    if (t.tm_mon + 1 == 11) {
        printf("   %s %d\n", nameMon[t.tm_mon], t.tm_year + 1900);
        printf(nameweeks);
        int day_1 = calculate_day_1(t.tm_mon + 1, t.tm_year + 1900);
        // printf("%d", day_1);
        day_mon(day_1, (t.tm_mon + 1));
    } else {
        printf("t.tm_mon: %d", t.tm_mon);
    }
}
int
main(void)
{
    // time_check_os();
    calendar_now();
}
