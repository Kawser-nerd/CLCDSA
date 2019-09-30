#include <stdio.h>
#include <stdlib.h>


typedef struct pair{
    long long a;
    long long b;
}ab;

//sub function to use qsort //
int compare_int(const void *x, const void *y)
{
    return (*(ab*)x).a - (*(ab*)y).a;
}

int main (void)
{
    long long n,m,i;
    scanf("%lld %lld",&n,&m);
    ab abx[n];
    for (i= 0; i< n; i ++)  {
        scanf("%lld %lld",&abx[i].a,&abx[i].b);   //b ... how many bottles a... money / bottle //
    }
    // input complete //
    qsort(abx, n, sizeof(ab), compare_int);
    int cnt = 0;
    long long money = 0;
    for  (i = 0;; i ++) {
        if (cnt + abx[i].b <= m)  {
            cnt +=  abx[i].b;
            money += abx[i].a * abx[i].b;
        }
        else {
            money += abx[i].a * (m - cnt);
            break;
        }
    }
    printf("%lld",money);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&m);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld",&abx[i].a,&abx[i].b);   //b ... how many bottles a... money / bottle //
         ^