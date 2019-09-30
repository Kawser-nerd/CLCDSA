#include <stdio.h>

int main(){
	int x1,y1,x2,y2,x,y,i;
  	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  
  	x=x2-x1;
  	y=y2-y1;
  
  	
      for(i=0;i<x;i++){
		printf("R");
      }
      for(i=0;i<y;i++){
		printf("U");
      }
      for(i=0;i<x;i++){
		printf("L");
      }
      for(i=0;i<y;i++){
		printf("D");
      }
      printf("D");
      for(i=0;i<x+1;i++){
		printf("R");
      }
      for(i=0;i<y+1;i++){
		printf("U");
      }
      printf("LU");
      for(i=0;i<x+1;i++){
		printf("L");
      }
      for(i=0;i<y+1;i++){
		printf("D");
      }
      printf("R");
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    ^