#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIV 1000000007

long long int calc(int a, int b){
  //printf("%d, %d\n",a, b);
  if(b==0) return 1;
  if(b%2==0){
    long long int d = calc(a, b/2);
    return (d*d)%DIV;
  }
  return (a*calc(a, b-1))%DIV;
}

int main(void){
  int w, h, i, j, ans;
  long long int p=1, q=1, r;
  scanf("%d %d",&w,&h);
  w--; h--;
  //for(i=0;i<w+h+1;i++) for(j=0;j<w+1;j++) DP[i][j]=-1;
  for(i=0;i<w;i++){
    p = (p*(w+h-i))%DIV;
    q = (q*(w-i))%DIV;
  }
  r = calc(q, DIV-2);
  //printf("p: %lld,  q: %lld, r: %lld\n",p, q, r);
  printf("%lld\n",(p*r)%DIV);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&w,&h);
   ^