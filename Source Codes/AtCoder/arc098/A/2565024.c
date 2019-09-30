#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
char s[300000];
int d[300001];

int main(void){
  int n, i, min;
  scanf("%d",&n);
  scanf("%s",s);
  d[0] = 0;
  for(i=0;i<n;i++){
    d[i+1] = 0;
    if(s[i] == 'E'){
      d[0]++;   d[i]--;
    } else {
      d[i+1]++;
    }
  }
  min = d[0];
  for(i=1;i<n;i++){
    d[i] += d[i-1];
    if(min > d[i]) min = d[i];
  }
  printf("%d\n",min);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^