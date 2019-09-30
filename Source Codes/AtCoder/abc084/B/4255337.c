#include <stdio.h>
int main(void){
    int A = 0; int B = 0;
    char S[20] = {0};
    scanf("%ld %ld", &A, &B);
    scanf("%s", S);
    int flag = 0;
    for(int i = 0; i < A + B + 1; i++){
        if(i == A){
            if(S[i] != 45){
                flag = 1;
                break;
            }
        }else {
            if(S[i] < 48 || S[i] > 57){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1){
        printf("No\n");
    }else {
        printf("Yes\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld %ld", &A, &B);
           ^
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &A, &B);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^