#include<stdio.h>

typedef long long int int64;

void run(void){
  int n,a,b,c,d;
  scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
  for(int64 i=0;i<=n-1;i++){
    int64 max=a+i*d-(n-1-i)*c;
    int64 min=a+i*c-(n-1-i)*d;
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
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
   ^