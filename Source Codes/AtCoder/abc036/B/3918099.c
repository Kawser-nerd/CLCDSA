#include<stdio.h>

int main(){
	int n,i,j;
	char s[50][51];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%c",s[n-j-1][i]);
		}
		puts("");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%s",s[i]);
                  ^