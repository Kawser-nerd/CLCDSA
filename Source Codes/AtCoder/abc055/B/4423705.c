#include <stdio.h>

int main()
{
  int i=1,N;
  long long int pw=1;
  scanf("%d",&N);
  for(i=1;i<=N;i++){
    pw = i*pw%1000000007; 
  }
  printf("%d",pw);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%d",pw);
          ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^