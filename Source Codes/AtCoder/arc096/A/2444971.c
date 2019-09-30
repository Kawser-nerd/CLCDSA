#include <stdio.h>

int main(){
    int A, B, C, X, Y;
    int n_a = 0, n_b = 0, n_c = 0;
    int result = 0;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    if((A + B) > 2 * C){
        if(X > Y){
            n_c += 2 * Y;
            X -= Y; Y = 0;
        }else{
            n_c += 2 * X;
            Y -= X; X = 0;
        }
    }
    if(X > 0){
        if(A > 2 * C){
            n_c += 2 * X;
        }else{
            n_a += X;
        }
        X = 0;
    }
    if(Y > 0){
        if (B > 2 * C){
            n_c += 2 * Y;
        }else{
            n_b += Y;
        }
        Y = 0;
    }
    printf("%d\n", A * n_a + B * n_b + C * n_c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
     ^