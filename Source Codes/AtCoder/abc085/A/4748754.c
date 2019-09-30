#include <stdio.h>
int main(void){
    int day;
    if (scanf("2017/01/%d", &day) == -1) return -1;
    printf("2018/01/%02d\n", day);
    return 0;
}