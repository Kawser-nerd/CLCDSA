#include <stdio.h>
#include <string.h>

int main(void) {
    int year, month, date;
    int heisei = 2019*365+3*30+30;
    if (scanf("%4d/%2d/%2d", &year, &month, &date) != EOF) {
        if (year*365+(month-1)*30+date <= heisei) {
            printf("Heisei");
        } else {
            printf("TBD");
        }
    } else {
        return 1;
    }
    return 0;
}