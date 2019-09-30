#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*w+(j))

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *now=(char *)calloc(h*w+1,sizeof(char));
  int i,j;
  for(i=0;i<h;i++) scanf("%s",now+POS(i,0));
  char *before=(char *)calloc(h*w+1,sizeof(char));
  for(i=0;i<h*w;i++) before[i]='#';

  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(now[POS(i,j)]=='.'){
	int x,y;
	for(x=i-1;x<=i+1;x++){
	  for(y=j-1;y<=j+1;y++){
	    if(0<=x && x<h && 0<=y && y<w){
	      before[POS(x,y)]='.';
	    }
	  }
	}
      }
    }
  }
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(now[POS(i,j)]=='#'){
	int find=0;
	int x,y;
	for(x=i-1;x<=i+1;x++){
	  for(y=j-1;y<=j+1;y++){
	    if(0<=x && x<h && 0<=y && y<w && before[POS(x,y)]=='#') find=1;
	  }
	}
	if(!find){
	  printf("impossible\n");
	  return;
	}
      }
    }
  }
  printf("possible\n");
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      printf("%c",before[POS(i,j)]);
    }
    printf("\n");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:11:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<h;i++) scanf("%s",now+POS(i,0));
                    ^