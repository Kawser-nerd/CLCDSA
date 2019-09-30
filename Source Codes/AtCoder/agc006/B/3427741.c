#include<stdio.h>

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  if(x==1 || x==2*n-1){
    printf("No\n");
    return;
  }
  printf("Yes\n");
  int k=2;
  int i;
  for(i=1;i<n-1;i++){
    if(k==x) k++;
    printf("%d\n",k++);
  }
  if(k-1<x){
    printf("%d\n%d\n%d\n",2*n-1,x,1);
  } else {
    printf("%d\n%d\n%d\n",1,x,2*n-1);
  }
  for(i=n+2;i<=2*n-1;i++){
    if(x==k) k++;
    printf("%d\n",k++);
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^