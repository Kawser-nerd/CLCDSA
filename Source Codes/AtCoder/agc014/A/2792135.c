#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  int cnt=0;
  const int p=100000;
  while(a%2==0 && b%2==0 && c%2==0 && cnt<p){
    int x=b/2+c/2;
    int y=a/2+c/2;
    int z=a/2+b/2;
    a=x;b=y;c=z;
    cnt++;
  }
  if(cnt>=100000) printf("-1\n");
  else printf("%d\n",cnt);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^