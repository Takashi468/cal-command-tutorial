// #include "calendar_now.h"
#include "users_input.h"
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char command[50];
    printf("===============================================\n");
    printf("select command\n");
    printf("1. cal - calender by entering the month.\n");
    printf("2. exit - exit program\n");
    printf("===============================================\n");
    for (;;) {
        scanf_s("%s", command);
        if (strcmp(command, "cal") == 0) {
            enter_mon_a_year();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknow command: %s\n", command);
        }
    }
    // time_check_os();
    // calendar_now();
}
