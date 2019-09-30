#include<stdio.h>

int main(void){
    long long int i, N, T, A, t, a, rt, ra, r;
    
    scanf("%ld", &N);
    
    scanf("%ld", &t);
    scanf("%ld", &a);
    
    for(i = 1; i < N; i++){
        scanf("%ld", &T);
        scanf("%ld", &A);
        
        rt = (t + T - 1) / T;
        ra = (a + A - 1) / A;
        
        if(rt > ra) r = rt;
        else r = ra;
        
        t = r * T;
        a = r * A;
    }
    
    printf("%lld\n", t + a);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld", &N);
           ^
./Main.c:8:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld", &t);
           ^
./Main.c:9:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld", &a);
           ^
./Main.c:12:15: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
         scanf("%ld", &T);
               ^
./Main.c:13:15: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
         scanf("%ld", &A);
               ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &N);...