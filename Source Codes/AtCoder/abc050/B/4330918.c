#include <stdio.h>
int main(void){
  int n,t[100],m,p[100],x[100],i;
  scanf("%d",&n);
  int total=0;
  for(i=0;i<n;i++){
    scanf("%d",&t[i]);
    total+=t[i];
  }
  int ttotal=total;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d %d",&p[i],&x[i]);
  }
  for(i=0;i<m;i++){
    total=ttotal;
    total=total-t[p[i]-1]+x[i];
    printf("%d\n",total);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t[i]);
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&p[i],&x[i]);
     ^