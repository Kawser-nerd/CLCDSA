#include<stdio.h>

int main(){
  long i,j,h,w,smax,smin,s[3],hh,hw,min=20000000000;
  scanf("%ld %ld",&h,&w);
  hh=h/2;
  for(i=1;i<=hh;i++){
    smin=smax=i*w;
    if(smin>(h-i)*(w/2))
      smin=(h-i)*(w/2);
    if(smax<(h-i)*(w-w/2))
      smax=(h-i)*(w-w/2);
    if(smax-smin<min)
      min=smax-smin;
    smin=smax=i*w;
    if(smin>(h-i)/2*w)
      smin=(h-i)/2*w;
    if(smax<((h-i)-((h-i)/2))*w)
      smax=((h-i)-((h-i)/2))*w;
    if(smax-smin<min)
      min=smax-smin;
  }
  hw=w/2;
  for(i=1;i<=hw;i++){
    smin=smax=i*h;
    if(smin>(w-i)*(h/2))
      smin=(w-i)*(h/2);
    if(smax<(w-i)*(h-h/2))
      smax=(w-i)*(h-h/2);
    if(smax-smin<min)
      min=smax-smin;
    smin=smax=i*h;
    if(smin>(w-i)/2*h)
      smin=(w-i)/2*h;
    if(smax<((w-i)-((w-i)/2))*h)
      smax=((w-i)-((w-i)/2))*h;
    if(smax-smin<min)
      min=smax-smin;
  }
  printf("%ld\n",min);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&h,&w);
   ^