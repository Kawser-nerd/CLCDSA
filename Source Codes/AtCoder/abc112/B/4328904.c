#include<stdio.h>

int main(void){
    int N,T,count=0;
    scanf("%d",&N);
    scanf("%d",&T);
    int min = 1000;
    for (int i;i<N;i++){
        int t,c;
        scanf("%d",&c);
        scanf("%d",&t);
        if (t <= T && c < min){
            min = c;
        } else if (t > T)
        {
            count++;
        }
        
    }

    if (count == N){
        printf("TLE");
    } else {
        printf("%d",min);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&T);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&c);
         ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t);
         ^