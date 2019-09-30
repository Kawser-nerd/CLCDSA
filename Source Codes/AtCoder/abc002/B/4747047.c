#include<stdio.h>
#include<string.h>
int main(void){
 char w[30];
 int i;
 scanf("%s",w);
 for(i=0;i<strlen(w);i++){
 	if(w[i] != 'a' && w[i] != 'i' &&
       w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
 	printf("%c",w[i]);
 }
	printf("\n");
     return 0;
 } ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",w);
  ^