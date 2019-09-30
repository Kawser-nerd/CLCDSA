#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void init(int *a,int n){
  int i;
  for(i=0;i<n;i++) a[i]=0;
  return;
}

void run(void){
  char s[8001];
  scanf("%s",s);
  int len=0;
  while(s[len]!='\0') len++;
  int x,y;
  scanf("%d%d",&x,&y);
  int i;
  for(i=0;i<len && s[i]=='F';i++,x--);
  const int m=8001;
  int *dx=(int *)malloc(sizeof(int)*m);
  int *dy=(int *)malloc(sizeof(int)*m);
  int *tmp=(int *)malloc(sizeof(int)*m);
  init(dx,m);
  init(dy,m);
  dx[0]=1;
  dy[0]=1;
  int dir=1;
  while(i<len){
    if(s[i]=='T'){
      dir^=1;
      i++;
    } else {
      int k=0;
      while(i<len && s[i]=='F'){
	k++;
	i++;
      }
      init(tmp,m);
      if(dir){
	int j;
	for(j=0;j<m-k;j++){
	  if(dx[j]){
	    tmp[ABS(j-k)]=1;
	    tmp[j+k]=1;
	  }
	}
	int *swap=dx;
	dx=tmp;
	tmp=swap;
      } else {
	int j;
	for(j=0;j<m-k;j++){
	  if(dy[j]){
	    tmp[ABS(j-k)]=1;
	    tmp[j+k]=1;
	  }
	}
	int *swap=dy;
	dy=tmp;
	tmp=swap;
      }
    }
  }
  printf("%s\n",dx[ABS(x)]==1 && dy[ABS(y)]==1?"Yes":"No");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^