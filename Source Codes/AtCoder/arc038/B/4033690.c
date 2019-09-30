#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*(w+1)+(j))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *s=(char *)calloc((h+1)*(w+1),sizeof(char));
  int i,j;
  for(i=0;i<h;i++) scanf("%s",s+POS(i,0));
  for(i=0;i<=h;i++) s[POS(i,w)]='#';
  for(j=0;j<=w;j++) s[POS(h,j)]='#';
  int *dp=(int *)calloc((h+1)*(w+1),sizeof(int));
  for(i=h-1;i>=0;i--){
    for(j=w-1;j>=0;j--){
      if(s[POS(i,j)]=='#') continue;
      int win=0;
      int dx[]={0,1,1};
      int dy[]={1,0,1};
      for(int k=0;k<3;k++){
	if(s[POS(i+dx[k],j+dy[k])]!='#' && dp[POS(i+dx[k],j+dy[k])]==0){
	  win=1;
	}
      }
      dp[POS(i,j)]=win;
    }
  }
  printf("%s\n",dp[POS(0,0)]?"First":"Second");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",s+POS(i,0));
                    ^