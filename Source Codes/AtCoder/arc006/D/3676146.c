#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))

int gcd(int a,int b){
  int r=a%b;
  while(r>0){
    a=b;b=r;r=a%b;
  }
  return b;
}

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *s=(char *)calloc(h*w+1,sizeof(char));
  int i,j;
  for(i=0;i<h;i++) scanf("%s",s+POS(i,0));
  int cntA=0,cntB=0,cntC=0;
  int *used=(int *)calloc(h*w,sizeof(int));
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(used[POS(i,j)] || s[POS(i,j)]=='.') continue;
      int x,y;
      for(x=0;s[POS(i+x,j)]=='o';x++);
      for(y=0;s[POS(i,j+y)]=='o';y++);
      int d=gcd(x,y);
      x/=d;
      y/=d;
      int dx,dy;
      if(x==1 && y==1){
	if(s[POS(i+d,j+d)]=='.'){
	  cntC++;
	  dx=1;
	  dy=2;
	} else if(s[POS(i+2*d,j+d)]=='o'){
	  cntB++;
	  dx=1;
	  dy=2;
	} else {
	  cntA++;
	  dx=1;
	  dy=3;
	}
      } else if(x==1 && y==3){
	if(s[POS(i+d,j+d)]=='o'){
	  cntA++;
	  dx=1;
	  dy=(s[POS(i+d,j-d)]=='o'?3:1);
	} else {
	  cntC++;
	  dx=1;
	  dy=2;
	}
      } else if(x==3 && y==1){
	cntA++;
	dx=1;
	dy=1;
      } else {
	cntB++;
	dy=(x==1?2:1);
	dx=1;
      }
      x=i-dx*d;
      y=j-dy*d;
      int k,l;
      for(k=x;k<x+7*d;k++) for(l=y;l<y+7*d;l++) used[POS(k,l)]=1;
    }
  }
  printf("%d %d %d\n",cntA,cntB,cntC);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:19:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",s+POS(i,0));
                    ^