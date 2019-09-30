#include <stdio.h>
#include <string.h>
int main(void){
    int N = 0; char S[100] = {0};
    scanf("%ld", &N);
    scanf("%s", S);
    if(N % 2 == 0){
        printf("-1\n");
    }else {
        int flag = 0;
        if(N % 6 == 3){
            for(int i = 0; i < (N / 3); i++){
                if(S[3 * i] != 'a'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 1] != 'b'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 2] != 'c'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                printf("-1\n");
            }else {
                printf("%d\n", (N-1) / 2);
            }
        }else if(N % 6 == 5){
            for(int i = 0; i < N / 3; i++){
                if(S[3 * i] != 'c'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 1] != 'a'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 2] != 'b'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                printf("-1\n");
            }else {
                printf("%d\n", (N-1) / 2);
            }
        }else if(N == 1){
            if(S[0] != 'b'){
                printf("-1\n");
            }else {
                printf("0\n");
            }
        }else {
            for(int i = 0; i < N / 3; i++){
                if(S[3 * i] != 'b'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 1] != 'c'){
                    flag = 1;
                    break;
                }
                if(S[3 * i + 2] != 'a'){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                printf("-1\n");
            }else {
                printf("%d\n", (N-1) / 2);
            }
        }
    }
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘int *’ [-Wformat=]
     scanf("%ld", &N);
           ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &N);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^