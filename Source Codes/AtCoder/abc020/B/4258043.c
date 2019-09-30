#include <stdio.h>
int main(void){
    int A = 0; int B = 0;
    scanf("%ld %ld", &A, &B);
    if(B / 100 >= 1){
        printf("%d\n", 2 * (A * 1000 + B));
    }else if(B / 10 < 10 && B / 10 >= 1){
        printf("%d\n", 2 * (A * 100 + B));
    }else {
        printf("%d\n", 2 * (A * 10 + B));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld", &A, &B);
           ^
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &A, &B);
     ^