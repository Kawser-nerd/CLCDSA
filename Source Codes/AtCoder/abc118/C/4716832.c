#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000


int gcd(int a, int b){
  if(a<b){
    int temp=a;
    a=b;
    b=temp;
  }
  int c;
  while(a%b!=0){
    c=a%b;
    a=b;
    b=c;
  }
  return b;
}


int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int *A=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    scanf("%d",&A[i]);
  }

  int ans;
  ans=gcd(A[0], A[1]);
  srep(i,2,N){
    ans=gcd(ans, A[i]);
  }

  printf("%d\n", ans);

  return 0;


} ./Main.c: In function ‘main’:
./Main.c:38:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^