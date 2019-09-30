#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
	int n;
	char ans[51],str[50][51];
	
	scanf("%d %s",&n,ans);
	for (int i = 1;i < n;i++) {
		scanf("%s",str[i-1]);
	}
	
	char tmp;
	for (int i = 0;i < strlen(ans);i++) {
		for (int j = i+1;j < strlen(ans);j++) {
			if (ans[i] > ans[j]) {
				tmp = ans[i];
				ans[i] = ans[j];
				ans[j] = tmp;
			}
		}
	}
	
	for (int i = 0;i < n-1;i++) {
		for (int j = 0;j < strlen(ans);j++) {
			bool flag = false;
			if (ans[j] == ' ') {
				continue;
			}
			for (int k = 0;k < strlen(str[i]);k++) {
				if (ans[j] == str[i][k]) {
					str[i][k] = ' ';
					flag = true;
					break;
				}
			}
			if (!flag) {
				ans[j] = ' ';
			}
		}
	}
	
	for (int i = 0;i < strlen(ans);i++) {
		if (ans[i] != ' '){
			printf("%c",ans[i]);
		}
	}
	printf("\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %s",&n,ans);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str[i-1]);
   ^