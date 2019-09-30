#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n,a,b,c,d;
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  int i;
  for(i=0;i<n;i++){
    int64 max=a+(int64)(n-1-i)*d-(int64)i*c;
    int64 min=a+(int64)(n-1-i)*c-(int64)i*d;
    if(min<=b && b<=max){
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
   ^