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
  char s[101];
  scanf("%s",s);
  int c=0;
  int i;
  for(i=0;i<n;i++){
    if(s[i]=='('){
      c++;
    } else if(c>0){
      c--;
    } else {
      putchar('(');
    }
  }
  printf("%s",s);
  for(i=0;i<c;i++) putchar(')');
  putchar('\n');
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