#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int a,b,c;
  scanf("%d %d %d", &a,&b,&c);

  int count=0;
  if(b <= c){
    count += 2*b;
    if(a < c - b){
      count+=a+1;
    }else{
      count+=c-b;
    }
  }else{
    count+=c+b;
  }
  printf("%d\n", count);
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a,&b,&c);
   ^