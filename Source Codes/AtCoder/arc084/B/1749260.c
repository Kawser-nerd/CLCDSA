#include<stdio.h>
int main(){
  int n,m=100000,q[100010],r,t,d[100010];
  scanf("%d",&n);
  q[t=0]=1;
  for(r=0;r<n;r++)d[r]=1e9;
  for(r=d[1]=1;r-t;t++){//printf("%d %d\n",q[t],d[q[t]]);
    if(d[(q[t]+1)%n]>d[q[t]]+1){
      d[(q[t]+1)%n]=d[q[t]]+1;
      q[r++]=(q[t]+1)%n;
    }
    if(d[(q[t]*10%n)]>d[q[t]]){
      d[(q[t]*10)%n]=d[q[t]];
      q[t]=(q[t]*10)%n;
      t--;
    }
  }
  printf("%d\n",d[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^