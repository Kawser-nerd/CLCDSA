#include <stdio.h>
int main(){
int i,k=0,j;
	char s[10];
for (i=0;i<12;i++){
	scanf("%s",s);
	for(j=0;j< strlen(s);j++){
	if(s [j]=='r')
	{
		k++;
		break;
	}
		
	}
	}
	printf("%d\n",k);
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:7:13: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for(j=0;j< strlen(s);j++){
             ^
./Main.c:7:13: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:7:13: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^