#include <stdio.h>

int main(){
  int a,b,c,x;
  scanf("%d\n%d\n%d\n%d",&a,&b,&c,&x,stdin);

  //500a+100b+50c == x                                                                  
  int count = 0;
  for(int i = 0; i <= a; ++i){
    int	sum = 500 * i;
    if(sum > x)	break;
    for(int j = 0; j <= b; ++j){
      sum = 500 * i + 100 * j;
      if(sum > x) break;
      for(int k = 0; k <= c; ++k){
        sum = 500 * i + 100 * j + 50 * k;
        if(sum == x) count++;
        if(sum > x) break;
      }
    }
  }
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: too many arguments for format [-Wformat-extra-args]
   scanf("%d\n%d\n%d\n%d",&a,&b,&c,&x,stdin);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n%d\n%d\n%d",&a,&b,&c,&x,stdin);
   ^