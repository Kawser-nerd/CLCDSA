#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,b[100010]={};
  int a,max=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    b[a]++;
  }
  for(i=1;i<100005;i++)max=MAX(max,b[i-1]+b[i]+b[i+1]);
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^