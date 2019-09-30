#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/


char name[1000000];
int n;
int len;


int main(void) {
    int num;
    long long int N;
    int i, j, k;


    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        char t;
        len = 0;
        gets(name);
        while((t = getchar()) != ' ') {
            switch(t) {
            case 'a':
            case 'i':
            case 'u':
            case 'e':
            case 'o':
                name[len] = 0;
                break;
            default:
                name[len] = 1;
            }
            ++len;
        }
        scanf("%d", &n);

        // ‘Oˆ—
        for(j = 0; j <= len-n; ++j) {
            for(k = 0; k < n; ++k) {
                if(!name[j+k]) break;
            }
            if(k < n) name[j] = 0;
        }

        N = 0;
        j = 0;

        while(j <= len-n) {
            for(k = j; k <= len-n; ++k) {
                if(name[k] == 1) break;
            }
            if(k > len-n) break; // ‚à‚¤‚È‚¢
            N += (long long int)(len-n-k+1)*(k-j+1);
            j = k + 1;
        }

        printf("Case #%d: %lld\n", i, N);
    }

    return 0;
}
