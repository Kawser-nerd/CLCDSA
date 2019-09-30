#include <stdio.h>

int main(void) {
    int year, month, day;
    scanf("%d%*[-/]%d%*[-/]%d", &year, &month, &day);

    const int score = year * 10000
        + month * 100
        + day
        ;   

    printf(score <= 20190430 ? "Heisei" : "TBD");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*[-/]%d%*[-/]%d", &year, &month, &day);
     ^