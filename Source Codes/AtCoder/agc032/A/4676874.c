#include <stdio.h>

int main(void)
{
  int N,i = 0,ans = 0,buf0 = 0,buf1 = 0,j = 0;
  scanf("%d",&N);
  int a[N],b[N];
  for(i = 0;i < N;i++) {
    scanf("%d",&b[i]);
  }

  while(j < N) {
    //printf("ans %d buf0 %d buf1 %d\n",ans,buf0,buf1);
    i = N - 1;
    ans = -1;
    buf0 = buf1 = 0;

    for(i = N - 1;i >= 0;i--) {
      //printf("b[%d] %d\n",i,b[i]);
      buf1 = b[i];

      if(b[i] == i + 1) {
        ans = b[i];
        a[j] = ans;
        b[i] = buf0;
        break;
      }
        //printf("a[%d] %d\n",i,a[i]);

      b[i] = buf0;
      buf0 = buf1;
    }

    if(ans == -1) break;

    j++;
  }

  if(ans == -1) {
    printf("-1\n");
  } else {
    i = N - 1;
    for(i = N - 1;i >= 0;i--) {
      printf("%d\n",a[i]);
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b[i]);
     ^