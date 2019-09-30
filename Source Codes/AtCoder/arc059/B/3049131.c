#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char *s=(char *)malloc(sizeof(char)*(100000+1));
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  int diff;
  int i;
  for(diff=1;diff<=2;diff++){
    for(i=0;i+diff<n;i++){
      if(s[i]==s[i+diff]){
	printf("%d %d\n",i+1,i+diff+1);
	return;
      }
    }
  }
  printf("-1 -1\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^