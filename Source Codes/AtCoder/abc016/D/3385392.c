//Cutting Polygon
//ABC016-D
#include<stdio.h>

typedef struct{
  long long x;
  long long y;
}Vec;

long long gaiseki(Vec a,Vec b){
  return (a.x)*(b.y)-(a.y)*(b.x);
}

int main(){
  long long i,j,ax,ay,bx,by,n,xz[128],yz[128],p,q,r=0;
  Vec base,move;
  scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
  scanf("%lld",&n);
  for(i=0;i<n;i++){
    scanf("%lld%lld",&xz[i],&yz[i]);
  }
  xz[n]=xz[0];
  yz[n]=yz[0];
  for(i=1;i<=n;i++){
    base.x=bx-ax;
    base.y=by-ay;
    move.x=xz[i-1]-ax;
    move.y=yz[i-1]-ay;
    p=gaiseki(base,move);
    move.x=xz[i]-ax;
    move.y=yz[i]-ay;
    q=gaiseki(base,move);
    if(p*q>0){continue;}
    base.x=xz[i]-xz[i-1];
    base.y=yz[i]-yz[i-1];
    move.x=ax-xz[i-1];
    move.y=ay-yz[i-1];
    p=gaiseki(base,move);
    move.x=bx-xz[i-1];
    move.y=by-yz[i-1];
    q=gaiseki(base,move);
    if(p*q>0){continue;}
    r++;
  }
  printf("%lld\n",1+(r/2));
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
   ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&xz[i],&yz[i]);
     ^