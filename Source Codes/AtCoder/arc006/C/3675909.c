#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n;
  scanf("%d",&n);
  int d[50];
  int len=1;
  scanf("%d",d+0);
  for(int i=1;i<n;i++){
    int w;
    scanf("%d",&w);
    int j;
    for(j=0;j<len && d[j]<w;j++);
    if(j==len){
      d[len++]=w;
      continue;
    }
    int min=j;
    for(;j<len;j++) if(d[j]>=w && d[j]<min) min=j;
    d[min]=w;
  }
  printf("%d\n",len);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",d+0);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&w);
     ^