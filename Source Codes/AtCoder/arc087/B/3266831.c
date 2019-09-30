#include<stdio.h>
#include<stdlib.h>

#define ABS(a) ((a)>(0)?(a):-(a))
#define POS(i,j,k) (((i)*2+(j))*(m+1)+ABS(k))

void init(int *a,int n){
  int i;
  for(i=0;i<n;i++) a[i]=0;
  return;
}

void run(void){
  const int m=8000;
  char *s=(char *)malloc(sizeof(char)*(m+1));
  scanf("%s",s);
  int len=0;
  while(s[len]!='\0') len++;
  int x,y;
  scanf("%d%d",&x,&y);
  int i;
  for(i=0;i<len && s[i]=='F';i++,x--);
  int *dp=(int *)calloc(2*2*(m+1),sizeof(int));
  dp[POS(0,0,0)]=1;
  dp[POS(1,0,0)]=1;
  int now[2]={0,0};
  int dir=0;
  while(i<len){
    while(i<len && s[i]=='T'){
      dir^=1;
      i++;
    }
    int k=0;
    while(i<len && s[i]=='F'){
      k++;
      i++;
    }
    init(dp+POS(dir,now[dir]^1,0),m+1);
    int next=now[dir]^1;
    int j;
    for(j=0;j<=m-k;j++){
      if(dp[POS(dir,now[dir],j)]){
	dp[POS(dir,next,j-k)]=1;
	dp[POS(dir,next,j+k)]=1;
      }
    }
    now[dir]=next;
  }
  printf("%s\n",dp[POS(0,now[0],x)] && dp[POS(1,now[1],y)]?"Yes":"No");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^