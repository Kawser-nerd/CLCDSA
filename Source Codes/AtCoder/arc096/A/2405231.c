#include<stdio.h>

long min(long x, long y){
  if(x<y) return x;
  else return y;
}

int main(){
  long a,b,c,x,y,sum=0;
  scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&x,&y);
  if(a+b>2*c){
    sum+=2*c*min(x,y);
    if(x>y){
      if(a<2*c) sum+=a*(x-y);
      else sum+=2*c*(x-y);
    }
    else{
      if(b<2*c) sum+=b*(y-x);
      else sum+=2*c*(y-x);
    }
  }
  else sum+=a*x+b*y;
  printf("%ld\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&x,&y);
   ^