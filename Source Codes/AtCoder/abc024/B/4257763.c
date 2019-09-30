#include <stdio.h>
int main(void){
    int N = 0; int T = 0;
    int A[100000] = {0};
    scanf("%ld %ld", &N, &T);
    for(int i = 0; i < N; i++){
        scanf("%ld", &A[i]);
    }
    int open = 0; int t = 0;
    for(int i = 0; i < N-1; i++){
        t = A[i] + T;
        if(t <= A[i+1]){
            open += T;
        }else {
            open += (A[i+1] - A[i]);
        }
    }
    printf("%d\n", open + T);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld", &N, &T);
           ^
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:7:15: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
         scanf("%ld", &A[i]);
               ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &N, &T);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &A[i]);
         ^