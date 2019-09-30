#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char *s=(char *)malloc(sizeof(char)*100001);
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  char c=s[n/2];
  int k=n/2;
  while(k<n && s[k]==c && s[n-1-k]==c) k++;
  printf("%d\n",k);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^