#include<stdio.h>

int main(void){
  int i,n,s,t,w=0,cnt=0;
  scanf("%d %d %d",&n,&s,&t);
  int d[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
  }
  
  for(i=0;i<n;i++){
    w += d[i];
    if(s<=w && w<=t){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&s,&t);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d[i]);
     ^