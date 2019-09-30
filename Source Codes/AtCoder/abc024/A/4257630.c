#include <stdio.h>
int main(void){
    int A, B, C, K = 0;
    int S, T = 0;
    scanf("%ld %ld %ld %ld", &A, &B, &C, &K);
    scanf("%ld %ld", &S, &T);
    int sum = 0;
    if(S + T >= K){
        sum = (A-C) * S + (B-C) * T;
    }else {
        sum = A * S + B * T;
    }
    printf("%d\n", sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld %ld %ld", &A, &B, &C, &K);
           ^
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 4 has type ‘int *’ [-Wformat=]
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 5 has type ‘int *’ [-Wformat=]
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld", &S, &T);
           ^
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld %ld", &A, &B, &C, &K);
  ...