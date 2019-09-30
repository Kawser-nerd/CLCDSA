#include<stdio.h>
 
 int main(void){
  char c[4][4];
  int i,j;
 	for(i=0;i<4;i++){
    for(j=0;j<4;j++){
     scanf("%s",&c[i][j]);
     }
   }
   for(i=0;i<4;i++){
    for(j=0;j<4;j++){
    	printf("%c",c[3-i][3-j]);
    	if(j==3){ printf("\n");
    		}else{ printf(" ");
    		}
      }
    }
    return 0;
 } ./Main.c: In function ‘main’:
./Main.c:8:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%s",&c[i][j]);
      ^