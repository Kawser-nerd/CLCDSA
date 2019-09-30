#include <stdio.h>

int main(void)
{
    int N;
    int i,j;
    int time=0;
    
    scanf("%d",&N);
    int A[N];
    
    for(i=0; i<N-1; i++){
        scanf("%d ",&A[i]);
    }
    scanf("%d",&A[N-1]);
    
    for(i=0; i<N-1; i++){
        if(A[i] == A[i+1]){
            time++;
            i++;
        }
    }
    
    printf("%d\n",time);
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d ",&A[i]);
         ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[N-1]);
     ^