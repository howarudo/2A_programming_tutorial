
#include <stdio.h>

int zeller(int, int, int);

int main () {
    int year = 2016; int month = 10; int day = 5;
    int w;
    w = zeller(year, month, day);
    printf("%d/%d/%d is ", year, month, day);
    switch(w) {
        case 0: printf("Sat.\n"); break;
        case 1: printf("Sun.\n"); break;
        case 2: printf("Mon.\n"); break;
        case 3: printf("Tue.\n"); break;
        case 4: printf("Wed.\n"); break;
        case 5: printf("Thurs.\n"); break;
        case 6: printf("Fri.\n"); break;
    }
    return 0;
}

int zeller(int year, int month, int day) {
    // Calculate h and y from zeller's alg
    int h = year / 100;
    int y = year % 100;
    // Calculate the alg
    int w = y + y/4 + h/4 - 2 * h + 13 * (month + 1) / 5 + day;
    // Find mod 7
    int w_mod7 = w % 7;
    return w_mod7;
}
