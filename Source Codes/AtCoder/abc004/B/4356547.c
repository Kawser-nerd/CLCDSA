#include <stdio.h>
int main(){
int j,i;
char s[5][5]={0};
	for(i=0;i<4;i++){
      for(j=0;j<4;j++){
	scanf ("%c ",&s[i][j]);
      }
    }
	for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	printf ("%c",s[3-i][3-j]);
		if(j==3){
	printf("\n");
			}
      else{
      printf(" ");
      }
	}
		}
	
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%c ",&s[i][j]);
  ^