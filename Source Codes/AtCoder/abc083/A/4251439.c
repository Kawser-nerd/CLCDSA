#include <stdio.h>
int main(void){
    int A, B, C, D = 0;
    scanf("%ld %ld %ld %ld", &A, &B, &C, &D);
    if(A + B > C + D){
        printf("Left\n");
    }else if(A + B < C + D){
        printf("Right\n");
    }else {
        printf("Balanced\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld %ld %ld", &A, &B, &C, &D);
           ^
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 4 has type ‘int *’ [-Wformat=]
./Main.c:4:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 5 has type ‘int *’ [-Wformat=]
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld %ld", &A, &B, &C, &D);
     ^