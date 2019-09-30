#include<stdio.h>
int main(){
  int n,x,m[100],i,min=1000,sum=0;
  scanf("%d%d",&n,&x);
  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
    sum+=m[i];
    if(min>m[i]) min=m[i];
  }
  printf("%d",n+(x-sum)/min);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m[i]);
     ^