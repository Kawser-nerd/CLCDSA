#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int N,a;
  int counter = 0;
  int ans = 0;
  int flag[9] = {0,0,0,0,0,0,0,0,0};
  scanf("%d",&N);

  for(int i = 0;i < N;i++){
    scanf("%d",&a);
    if(a < 400) flag[0] = 1;
    else if(a < 800) flag[1] = 1;
    else if(a < 1200) flag[2] = 1;
    else if(a < 1600) flag[3] = 1;
    else if(a < 2000) flag[4] = 1;
    else if(a < 2400) flag[5] = 1;
    else if(a < 2800) flag[6] = 1;
    else if(a < 3200) flag[7] = 1;
    else flag[8]++;
  }


  for(int i = 0;i < 8;i++){
    if(flag[i]) counter++;
  }
  printf("%d %d\n",max(1,counter),counter+flag[8]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^