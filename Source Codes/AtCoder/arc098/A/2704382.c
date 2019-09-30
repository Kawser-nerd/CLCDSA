#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  int cntE=0;
  int i;
  for(i=0;i<n;i++){
    if(s[i]=='E') cntE++;
  }
  int min=n;
  int cntW=0;
  for(i=0;i<n;i++){
    if(s[i]=='E') cntE--;
    min=MIN(min,cntE+cntW);
    if(s[i]=='W') cntW++;
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^