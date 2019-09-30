#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*n+(j)%n)

void run(void){
  int n;
  scanf("%d",&n);
  char *board=(char *)calloc(n*n+1,sizeof(char));
  int i,j,k;
  for(i=0;i<n;i++) scanf("%s",board+POS(i,0));
  int ans=0;
  for(k=0;k<n;k++){
    int flag=1;
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(board[POS(i,j+k)]!=board[POS(j,i+k)]) flag=0;
      }
    }
    if(flag) ans+=n;
  }
  printf("%d\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%s",board+POS(i,0));
                    ^