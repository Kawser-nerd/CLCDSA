#include<stdio.h>
int main(){
  int n,m,i,a,b[20]={0};
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d",&a);
    b[a]=1;
  }
  while(1){
    for(i=n++;i&&b[i%10]==0;i/=10);
    if(i==0)break;
  }
  printf("%d\n",n-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^