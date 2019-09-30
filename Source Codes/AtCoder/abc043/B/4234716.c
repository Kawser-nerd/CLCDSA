#include <stdio.h>
#include <string.h>

char s[100];
char buf[100];

int main(){
	scanf("%s",s);
	int len = strlen(s);
	int i;
	int cnt = 0;
	for(i = 0 ;i<len;i++){
		if(s[i] == 'B'){
			if(cnt > 0){
				buf[--cnt] = 0;
			}
		}else
			buf[cnt++] = s[i];
	}
	printf("%s\n",buf);
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^