#include <stdio.h>
int main(void){
    int N = 0; int S = 0; int T = 0;
    int W = 0;
    scanf("%ld %ld %ld", &N, &S, &T);
    scanf("%ld", &W);
    int A[10000] = {0};
    for(int i = 2; i <= N; i++){
        scanf("%ld", &A[i]);
    }
    int day = 0;
    if(W >= S && W <=T){
        day++;
    }
    for(int i = 2; i <= N; i++){
        W += A[i];
        if(W >= S && W <= T){
            day++;
        }
    }
    printf("%d\n", day);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld %ld", &N, &S, &T);
           ^
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 4 has type ‘int *’ [-Wformat=]
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld", &W);
           ^
./Main.c:9:15: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
         scanf("%ld", &A[i]);
               ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &N, &S, &T);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unuse...