#include<stdio.h>

#define ABS(x) (((x)<(0))?(-(x)):(x))

int main(void){
  int N,t,x,y,nx=0,ny=0,nt=0;
  int i,j,k,tmp;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d%d%d",&t,&x,&y);
    tmp=t-nt-(ABS(x-nx)+ABS(y-ny));
      if(tmp<0 || tmp%2){
	puts("No");
	return 0;
      }
  }
  puts("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&t,&x,&y);
     ^