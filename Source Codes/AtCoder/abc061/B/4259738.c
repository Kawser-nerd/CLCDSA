#include <stdio.h>
int main(void){
  int n,m,i;
  int a[50],b[50],road[50]={0};
  scanf("%d%d",&n,&m);
  for(i=1;i<=m;i++){
    scanf("%d %d",&a[i],&b[i]);
    road[a[i]]++;
    road[b[i]]++;
  }
  for(i=1;i<=n;i++){
    printf("%d\n",road[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a[i],&b[i]);
     ^