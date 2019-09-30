#include <stdio.h>
int main(){
  int n,m,t[111],p,x,i,j,sum;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&t[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d%d",&p,&x);
    sum=0;
    for(j=0;j<n;j++){
      sum+=t[j];
    }
    sum+=x-t[p-1];
    printf("%d\n",sum);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t[i]);
     ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p,&x);
     ^