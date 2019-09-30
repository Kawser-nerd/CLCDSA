#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*n+(j))

int isSymmetric(const int k,const char *board,const int n){
  int i;
  for(i=0;i<n;i++){
    int x=i;
    int y=(k+i)%n;
    int j=1;
    while(j<n && board[POS((x+j)%n,(y-j+n)%n)]==board[POS((x-j+n)%n,(y+j)%n)]){
      j++;
    }
    if(j<n){
      //printf("%d %d error\n",k,i);
      return 0;
    }
  }
  for(i=0;i<n-1;i++){
    int x=i;
    int y=(k+i+1)%n;
    int j=0;
    while(j<n && board[POS((x+j)%n,(y-j+n)%n)]==board[POS((x+1-j+n)%n,(y-1+j+n)%n)]){
      j++;
    }
    if(j<n) return 0;
  }
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  char board[90001];
  int i;
  for(i=0;i<n;i++) scanf("%s",board+POS(i,0));

  int ans=0;
  for(i=0;i<n;i++){
    ans+=n*isSymmetric(i,board,n);
  }
  printf("%d\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:44:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%s",board+POS(i,0));
                    ^