#include <stdlib.h>
#include <stdio.h>
#define REP(i, n) for(i = 0; i < n; ++i)
#define FOR(i, a, b) for(i = a; i < b; ++i)

typedef struct{
    int a;
    int b;
}nums;

void yes_or_no(char boolean){
    if(boolean){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
}

int comp(const void * a, const void * b){
    nums s_a = *(nums*)a, s_b = *(nums*)b;
    return s_a.a - s_b.a;
}

int main(){
    int i, N;
    long int K;
    scanf("%d %ld", &N, &K);
    nums x[N];
    int ans = 0;
    REP(i, N){
        scanf("%d %d", &x[i].a, &x[i].b);
    }
    qsort(x, N, sizeof(nums), comp);
    REP(i, N){
        K -= x[i].b;
        if(K <= 0){
            ans = x[i].a;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %ld", &N, &K);
     ^
./Main.c:31:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x[i].a, &x[i].b);
         ^