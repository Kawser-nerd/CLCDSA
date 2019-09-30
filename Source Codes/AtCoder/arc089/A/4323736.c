#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,x0=0,y0=0,t0=0,x,y,t;
  scanf("%d",&n);
  int i,d,dt,ans=1;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&t,&x,&y);
    d=abs(x-x0)+abs(y-y0);
    dt=t-t0;
    if(dt<d||(dt-d)%2==1){
      ans=0;
      break;
    }
    else{
      x0=x;
      y0=y;
      t0=t;
    }
  }
  puts(ans?"Yes":"No");
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&t,&x,&y);
     ^