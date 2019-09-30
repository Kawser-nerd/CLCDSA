#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char s[101];
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  int min=n-1;
  int i,j;
  for(i=0;i<n;i++){
    int local=0;
    for(j=0;j<n;j++){
      int k;
      for(k=j;k<n;k++){
	if(s[k]==s[i]) break;
      }
      local=MAX(local,k-j);
    }
    min=MIN(local,min);
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^