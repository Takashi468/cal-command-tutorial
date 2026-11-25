#include "calendar.h"
#include "users_input.h"
#include <stdio.h>
#include <string.h>

void
help()
{
    printf("===============================================\n");
    printf("select command\n");
    printf("1. cal - calender by entering the month.\n");
    printf("2. exit - exit program\n");
    printf("3. help - view command\n");
    printf("===============================================\n");
}

int
main(void)
{
    char command[50];
    help();
    for (;;) {
        scanf_s("%s", command);
        if (strcmp(command, "cal") == 0) {
            enter_mon_a_year();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "help") == 0) {
            help();
        } else if (strcmp(command, "now") == 0) {
            calendar_now();

        } else {
            printf("Unknow command: %s\n", command);
        }
    }
    // time_check_os();
    // calendar_select();
}
