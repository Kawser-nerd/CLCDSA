#include<stdio.h>
#include<stdlib.h>

void run(void){
  char *x=(char *)malloc(sizeof(char)*(200000+1));
  scanf("%s",x);
  char *s=(char *)malloc(sizeof(char)*(200000+1));
  int top=0;
  int n=0;
  while(x[n]!='\0'){
    s[top++]=x[n++];
    if(top>1 && s[top-1]=='T' && s[top-2]=='S') top-=2;
  }
  printf("%d\n",top);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",x);
   ^