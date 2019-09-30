#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  unsigned long long int score, pre, ans, r, j;
  int q, a, b, i, dis, t;
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d %d",&a, &b);
    if(a<b){t=a; a=b; b=t;}
    score = (unsigned long long int) a*b;
    pre = -1;  dis=0;
    //printf("%d: s=%llu\n",i,score);
    for(j=sqrt(score); ;j++){
      r=score/j;
      if(score%j==0) r--;
      if(r==pre) break;
      if(j==a || r==b) dis++;
      else pre=r;
      //printf("%llu->",r);
    }
    //printf(".\n");
    if(r>b) dis++;
    ans = r+j-2-dis;
    printf("%llu\n",ans);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a, &b);
     ^