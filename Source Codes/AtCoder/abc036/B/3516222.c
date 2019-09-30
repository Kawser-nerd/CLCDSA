#include <stdio.h>
int main(void){
	int n,i;
	scanf("%d",&n);
	char s[50][51];
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			printf("%c",s[j][i]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%s",s[i]);
                  ^