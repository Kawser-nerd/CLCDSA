#include<math.h>
#include<stdio.h>

int main(void)
{
     int  N,i;
     scanf("%d",&N);
     printf("1");
     for(i = 0; i < N - 1; i++) {
          printf("0");
     }
     printf("7\n");
     return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&N);
      ^