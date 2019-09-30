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
  const int m=1000000;
  int cnt=0;
  while(a%2==0 && b%2==0 && c%2==0 && cnt<m){
    int x=b/2+c/2;
    int y=a/2+c/2;
    int z=b/2+a/2;
    a=x;b=y;c=z;
    cnt++;
    //printf("%d %d %d\n",a,b,c);
  }
  printf("%d\n",cnt<m?cnt:-1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^