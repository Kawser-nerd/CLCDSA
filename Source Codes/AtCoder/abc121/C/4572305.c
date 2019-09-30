#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned long long a;
    int b;
} drink;
int cmp(const void *p, const void *q) {
    return ((drink *)p)->a - ((drink *)q)->a;
}
int main(void){
    int n, m, i;
    unsigned long long cost=0;
    scanf("%d %d", &n, &m);
    drink monster[n];
    for(i=0; i<n; i++)
        scanf("%lld %lld", &monster[i].a, &monster[i].b);
    qsort(monster, n, sizeof(drink), cmp);
    for(i=0; m>0; i++){
        if(monster[i].b < m){
            cost += monster[i].a * monster[i].b;
            m -= monster[i].b;
        }else{
            cost += monster[i].a * m;
            break;
        }
    }
    printf("%lld\n", cost);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:15: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘int *’ [-Wformat=]
         scanf("%lld %lld", &monster[i].a, &monster[i].b);
               ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld", &monster[i].a, &monster[i].b);
         ^