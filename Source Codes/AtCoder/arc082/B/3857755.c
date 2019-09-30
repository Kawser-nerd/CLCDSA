#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n;
  scanf("%d",&n);
  int *p=(int *)calloc(n+2,sizeof(int));
  int i;
  for(i=1;i<=n;i++){
    scanf("%d",p+i);
  }
  int cnt=0;
  for(i=1;i<=n;i++){
    if(p[i]==i){
      cnt++;
      p[i+1]=i;
    }
  }
  printf("%d\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",p+i);
     ^