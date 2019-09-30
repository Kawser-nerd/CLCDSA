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
  char *t[]={"dream","dreamer","erase","eraser"};
  int len[]={5,7,5,6};
  while(n>0){
    int i;
    for(i=0;i<4;i++){
      if(n<len[i]) continue;
      int j;
      for(j=0;j<len[i];j++){
	if(s[n-len[i]+j]!=t[i][j]) break;
      }
      if(j>=len[i]){
	n-=len[i];
	break;
      }
    }
    if(i==4){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^