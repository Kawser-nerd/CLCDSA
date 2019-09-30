#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

long double f_times[100000]; // nŒÂfarm‚ğ”ƒ‚¤‚Ü‚Å‚ÌŠÔ
double c, f, x;

int main(void) {
    int num;
    int try_num;

    int max_f;
    int i;

    scanf("%d", &num);
    for(try_num = 1; try_num <= num; ++try_num) {
        double cps = 2.0;
        double least;
        scanf("%lf %lf %lf", &c, &f, &x);

        f_times[0] = 0.0;
        least = x / 2;

        printf("Case #%d: ", try_num);
        for(i = 1; i < 100000; ++i) {
            double temp;
            f_times[i] = c / cps + f_times[i-1];
            if(f_times[i] > least) { // ì‚é‚Ü‚Å‚É‚»‚ê‚Ü‚Å‚ÌÅ’ZŠÔ‚ğ’´‚¦‚½
                break;
            }
            cps = 2.0 + f * i; // —İÏŒë·‹N‚±‚é‚©H
            temp = f_times[i] + x / cps;
            if(temp < least) least = temp;
        }
        printf("%llf\n", least);

    }

    return 0;
}
