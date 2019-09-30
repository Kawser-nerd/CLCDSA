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

int main(){
  char buf[1024];
  int A,B;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &A, &B);

  if(B%A==0){
    printf("%d\n",A+B);
  }
  else{
    printf("%d\n",B-A);
  }

  return 0;


} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^