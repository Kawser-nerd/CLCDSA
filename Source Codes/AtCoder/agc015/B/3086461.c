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
  int64 ans=(n-1)+(n-1);
  int i;
  for(i=1;i<n-1;i++){
    if(s[i]=='U'){
      ans+=1*(n-1-i)+2*i;
    } else {
      ans+=1*i+2*(n-1-i);
    }
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^