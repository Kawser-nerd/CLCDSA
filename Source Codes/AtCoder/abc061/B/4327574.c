#include<stdio.h>
int main(){
  int n,m,a,b,ans[55]={},i;
  scanf("%d%d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d%d",&a,&b);
    ans[a-1]++;
    ans[b-1]++;
  }
  for(i=0;i<n;i++){
    printf("%d\n",ans[i]);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^