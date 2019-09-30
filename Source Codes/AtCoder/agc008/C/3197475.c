#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int a[7];
  int i;
  for(i=0;i<7;i++) scanf("%d",a+i);
  int64 ans=2*a[1];//2*2
  const int I=a[0];
  const int L=a[3];
  const int iL=a[4];
  ans+=4*(I/2);//1*4
  ans+=4*(L/2);//L
  ans+=4*(iL/2);//inv L
  if(I>0 && L>0 && iL>0){
    if(I%2==1 && L%2==1 && iL%2==1){
      ans+=6;
    } else if(I%2+L%2+iL%2==2){
      ans+=2;
    }
  }
  printf("%lld\n",ans/2);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:9:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<7;i++) scanf("%d",a+i);
                    ^