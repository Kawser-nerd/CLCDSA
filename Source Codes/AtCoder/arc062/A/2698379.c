#include<stdio.h>

long max(long x,long y){
  if(x>y)
    return x;
  return y;
}

int main(){
  int n,i;
  long t[1000],a[1000],ansx=0,ansy=0,x,y,z;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%ld %ld",&t[i],&a[i]);
  ansx=t[0];
  ansy=a[0];
  for(i=1;i<n;i++){
    x=t[i];
    y=a[i];
    z=max(ansx/x,ansy/y);
    if(ansx<=x*z&&ansy<=y*z){
      ansx=x*z;
      ansy=y*z;
    }
    else{
      z+=1;
      ansx=x*z;
      ansy=y*z;
    }
  }
  printf("%ld\n",ansx+ansy);
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&t[i],&a[i]);
     ^