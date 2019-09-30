#include <stdio.h>
int main(void){
	int n,i,j;
	char s[51][51];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(j=0;j<n;j++){
		for(i=n-1;i>=0;i--){
			printf("%c",s[i][j]);
			if(i==0) printf("\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i]);
   ^