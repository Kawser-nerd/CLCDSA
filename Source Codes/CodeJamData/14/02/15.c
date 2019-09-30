#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

long double f_times[100000]; // n��farm�𔃂��܂ł̎���
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
            if(f_times[i] > least) { // ���܂łɂ���܂ł̍ŒZ���Ԃ𒴂���
                break;
            }
            cps = 2.0 + f * i; // �ݐό덷�N���邩�H
            temp = f_times[i] + x / cps;
            if(temp < least) least = temp;
        }
        printf("%llf\n", least);

    }

    return 0;
}
