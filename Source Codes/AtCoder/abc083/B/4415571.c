#include <stdio.h>

int main(){
  int n,a,b;
  scanf("%d %d %d",&n,&a,&b,stdin);
  int answer = 0;
  int sum;
  for(int i = 1; i <= n; ++i){
    sum = i % 10 + (i/10) % 10 + (i/100) % 10 + (i/1000) % 10 + (i/10000) % 10;
    if(a <= sum && sum <= b) answer += i;
  }
  printf("%d\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%d %d %d",&n,&a,&b,stdin);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b,stdin);
   ^