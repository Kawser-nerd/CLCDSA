#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int try_attack(long long a, long long b, int ntry, int num, long long list[]);

int main(int argc, char *argv[])
{
    int n, i;
    long long list[100000] = {0}, a, b;
    int max = 1000000000, min = 0, v, ntry = 0;

    scanf("%d %d %d\n", &n, &a, &b);
    for ( i = 0; i < n; i++ ){
        scanf("%d\n", &v);
        list[i] = v;
    }

    do {
        ntry = (max + min)/2;
        if ( try_attack(a, b, ntry, n, list) == 0 ){
            min = ntry;
        } else {
            max = ntry;
        }
        if ( max - min < 10 ){
            break;
        }
    } while(1);

    for ( i = min; i <= max; i++ ){
        if ( try_attack(a, b, i, n, list) ){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

static int try_attack(long long a, long long b, int ntry, int num, long long list[])
{
    long long tmp[100000];
    int i, add = ntry;

    if ( num < 0 ){
        return 0;
    }

    memcpy(tmp, list, sizeof(tmp));
    for ( i = 0; i < num; i++ ){
        tmp[i] -= (b*ntry);
        if ( tmp[i] > 0 ){
            if ( tmp[i] % (a-b) == 0 ){
                add -= (tmp[i]/(a-b));
            } else {
                add -= (tmp[i]/(a-b) + 1);
            }
            if ( add < 0 ){
                return 0;
            }
        }
    }
    return 1;
} ./Main.c: In function ‘main’:
./Main.c:13:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
     scanf("%d %d %d\n", &n, &a, &b);
           ^
./Main.c:13:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘long long int *’ [-Wformat=]
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d\n", &n, &a, &b);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d\n", &v);
         ^