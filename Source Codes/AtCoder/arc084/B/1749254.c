#include<stdio.h>
int main(){
  int n,m=100000,q[100010],r,t,s,d[100010];
  scanf("%d",&n);
  q[t=0]=1;
  for(r=0;r<n;r++)d[r]=1e9;
  for(r=d[1]=1;r-t;t++){//printf("%d %d\n",q[t],d[q[t]]);
    s=q[t];
    if(d[(s*10%n)]>d[s]){
      d[(s*10)%n]=d[s];
      q[t]=(s*10)%n;
      t--;
    }
    if(d[(s+1)%n]>d[s]){
      d[(s+1)%n]=d[s]+1;
      q[r++]=(s+1)%n;
    }
  }
  printf("%d\n",d[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^