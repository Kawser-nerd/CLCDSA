#include <stdio.h>
#include <string.h>
int main(void){
	char s[2];
	int i,n,y=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s);
		if(strchr(s,'Y')!=NULL) y++;
	}
	if(y==0) printf("Three\n");
	else printf("Four\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^