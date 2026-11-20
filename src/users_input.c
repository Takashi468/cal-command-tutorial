#include <stdio.h>

int
enter_mon_a_year(void)
{
    char mon[30];
    printf("Enter mon: ");
    scanf_s("%s", mon);
    printf("%s", mon);
    return 0;
}
