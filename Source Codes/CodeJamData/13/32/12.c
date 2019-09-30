#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/


int main(void) {
    int num;
    int N;
    int i, j, k;
    int X, Y;
    int l, r;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d %d", &Y, &X); // XY•½–Ê‹t‚É‚µ‚Ä‚½‚—
        // j‚Ístep‚Ì•i‰ñ”j
        l = 0;
        r = 0;
        printf("Case #%d: ", i);
        j = 1;
        if(X > 0) {
            for( ; l < X; ++j) {
                l += j;
                putchar('N');
            }
        }
        else if(X < 0) {
            for( ; l > X; ++j) {
                l -= j;
                putchar('S');
            }
        }
        if(Y > 0) {
            for( ; r < Y; ++j) {
                r += j;
                putchar('E');
            }
        }
        else if(Y < 0) {
            for( ; r > Y; ++j) {
                r -= j;
                putchar('W');
            }
        }

        if(X > 0) {
            while(l != X) {
                l--;
                printf("NS");
            }
        }
        else {
            while(l != X) {
                l++;
                printf("SN");
            }
        }

        if(Y > 0) {
            while(r != Y) {
                r--;
                printf("EW");
            }
        }
        else {
            while(r != Y) {
                r++;
                printf("WE");
            }
        }
        puts("");
    }

    return 0;
}
