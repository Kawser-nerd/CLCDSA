#include <stdio.h>
#define LEN 10
int main(void){
    // Your code here!
    int N,L[LEN];
    int max,sum=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&L[i]);
    }
    max=L[0];
    for(int i=1;i<N;i++){
        if(L[i]>max){
            sum += max;
            max=L[i];
        }else{
            sum += L[i];
        }
    }
    
    if(sum>max){
        printf("Yes");
    }else{
        printf("No");
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&L[i]);
         ^