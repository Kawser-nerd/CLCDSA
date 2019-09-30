#include <stdio.h>
#include <string.h>
int main(void){
	char w[101],s[101];
	int i,j,c[101];
	scanf("%s",w);
	for(i=0;i<strlen(w);i++){
		c[i]=0;
	}
	strcpy(s,w);
	for(i=0;i<strlen(w);i++){
		if(w[i]=='0') continue;
		for(j=0;j<strlen(w);j++){
			if(s[i]==w[j]){
				c[i]++;
				w[j]='0';
			}
		}
	}
	for(i=0;i<strlen(w);i++){
		if(c[i]%2!=0){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",w);
  ^