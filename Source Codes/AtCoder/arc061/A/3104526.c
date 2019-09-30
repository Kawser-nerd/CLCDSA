#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int64 sum=0;

int64 calc(int index,int n,char *s){
  if(index==n) return sum;
  int64 res=0;
  int64 m=0;
  int i;
  for(i=index;i<n;i++){
    int d=s[i]-'0';
    m=10*m+d;
    sum+=m;
    res+=calc(i+1,n,s);
    sum-=m;
  }
  return res;
}

void run(void){
  char s[11];
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  int64 ans=calc(0,n,s);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^