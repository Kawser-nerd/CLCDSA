#include <stdio.h>
int main(void){
    int m, VV = 0;
    if (scanf("%d", &m) == -1) return -1;
    if (m < 100) VV = 0;
    else if (m >= 100 && m <= 5000) VV = m / 100;
    else if (m >= 6000 && m <= 30000) VV = m / 1000 + 50;
    else if (m >= 35000 && m <= 70000) VV = (m / 1000 - 30) / 5 + 80;
    else if (m > 70000) VV = 89;
    printf("%02d\n", VV);
    return 0;
}