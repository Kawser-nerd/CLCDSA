#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void){
  struct boxball{
  	int ball;
    bool red;
  }box[100001];
  int n,m,i,c=0;
  int x,y;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++){
  	box[i]=(struct boxball){1,false};
  }
  box[0]=(struct boxball){1,true};
  for(i=0;i<m;i++){
  	scanf("%d%d",&x,&y);
    box[x-1].ball--;
    box[y-1].ball++;
    if(box[x-1].red){
    	box[y-1].red=true;
      if(box[x-1].ball==0) box[x-1].red=false;
    }
  }
  for(i=0;i<n;i++){
  	c+=box[i].red;
  }
  printf("%d\n",c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:18:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d",&x,&y);
    ^