#include<stdio.h>
int main(){
  int n,m,a,i,j=1,d[10]={};
  scanf("%d %d",&m,&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    d[a]=1;
  }
  for(i=m;j;i++){
    for(j=i;j;j/=10){
      if(d[j%10])break;
    }
  }
  printf("%d\n",i-1);      
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&m,&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^