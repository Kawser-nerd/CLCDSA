#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int elem(char *s,int n,char c){
  int i;
  for(i=0;i<n;i++) if(s[i]==c) return 1;
  return 0;
}

void run(void){
  char s[1001];
  scanf("%s",s);
  int n;
  for(n=0;s[n]!='\0';n++);
  if(elem(s,n,'N')==elem(s,n,'S') && elem(s,n,'W')==elem(s,n,'E')){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^