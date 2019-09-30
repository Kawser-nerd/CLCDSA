#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
  int n;
  float x;
  char u[4];
  int ix;
  float sum = 0.0;
  
  scanf("%d",&n);
  for( ix = 0; ix < n; ix++ ){
    scanf("%f %s",&x,u);
    if( strstr(u,"JPY") ){
      sum += x;
    }
    else if( strstr(u,"BTC") ){
      sum += x * 380000.0;
    }
  }
  printf("%f\n",sum);
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%f %s",&x,u);
     ^