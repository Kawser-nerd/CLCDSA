#include<stdio.h>
int main(){
  int n,m=0,d,i,k=1,p[200010],f[200010]={};
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&d);
    p[d]=i+1;
  }
  p[0]=n+1;
  p[n+1]=0;
  for(i=1;i<=n;i++){
    if(p[i-1]<p[i]&&p[i]<p[i+1])f[i]=1;
    if(p[i-1]<p[i]||p[i]<p[i+1])k=2;			
  }
  d=0;
  for(i=1;i<=n;i++){
    if(f[i])d++;
    else    d=0;
    if(m<d)m=d;
  }
  //if(m<d)m=d;printf("%d\n",m);
  printf("%d\n",n-m-k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d);
     ^