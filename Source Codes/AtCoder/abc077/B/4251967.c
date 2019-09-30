#include <stdio.h>

int main(void){
    int N,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        if(i*i>N){
            break;
        }
    }
    printf("%d\n",(i-1)*(i-1));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^