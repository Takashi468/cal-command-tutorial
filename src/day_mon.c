#include "day_mon.h"
#include <stdio.h>

int
check_mon(int month)
{
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        // printf("เดือนนี้มี 31 วัน\n");
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        // printf("เดือนนี้มี 30 วัน\n");
        return 30;
        break;

    case 2:
        // printf("เดือนนี้มี 28 หรือ 29 วัน\n");
        return 28;
        break;

    default:
        printf("กรอกหมายเลขเดือนไม่ถูกต้อง\n");
        return 0;
        break;
    }
}

int
day_mon(int start, int mon)
{
    // printf("start: %d", start);
    // printf("mon: %d", mon);
    printf("\n");
    int i;
    int count_day;
    int count_day2 = start;
    // for (i = 0; i <= start; i++) {
    for (i = 0; i < start; i++) {
        printf("   ");
    }
    // if (i == start) {
    for (count_day = 1; count_day <= check_mon(mon); count_day++) {
        count_day2 += 1;
        printf("%3d", count_day);
        if (count_day2 % 7 == 0) {
            printf("\n");
        }
    }
    // }
    // }
    return 0;
}
