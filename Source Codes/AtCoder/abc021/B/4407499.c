#include<stdio.h>
int main(){
  int n,k,a[111]={},p,i;
  scanf("%d%d%d%d",&n,&p,&i,&k);
  a[p]++;
  a[i]++;
  for(i=0;i<k;i++){
    scanf("%d",&p);
    a[p]++;
  }
  for(i=1;i<=n;i++){
    if(a[i]>1) break;
  }
  puts(i>n?"YES":"NO");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&p,&i,&k);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p);
     ^