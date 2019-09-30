#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n;
  scanf("%d",&n);
  int *index=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++){
    int p;
    scanf("%d",&p);
    index[p-1]=i;
  }
  int max=0;
  i=0;
  while(i<n){
    int j=i+1;
    while(j<n && index[j]>index[j-1]) j++;
    if(max<j-i) max=j-i;
    i=j;
  }
  printf("%d\n",n-max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p);
     ^