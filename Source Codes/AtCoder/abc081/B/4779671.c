#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d",&N);
    
    int board[N];
    int count[N];
    
    int i;
    
    for (i=0;i<N;i++) {
        scanf("%d",&board[i]);
    }
    
    for (i=0;i<N;i++) {
        count[i] = 0;
    }
    
    int INF = 1000000;
    int res = INF;
    
    for (i=0;i<N;i++) {
        while (board[i]%2 == 0) {
            board[i] = board[i]/2;
            count[i]++;
        }
        if (res>count[i]) res = count[i];
    }
  
    //???count[]???????????????????????//
    printf("%d\n",res);
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&board[i]);
         ^