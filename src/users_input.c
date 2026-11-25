#include <calendar.h>
#include <stdio.h>

int
enter_mon_a_year(void)
{
    char mon;
    printf("Enter month in 2026: ");
    scanf_s("%d", &mon);
    // printf("%d", mon);
    calendar_select(mon);
    return 0;
}
