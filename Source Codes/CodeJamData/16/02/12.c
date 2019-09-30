#include<stdio.h>

char str[128];

int main() {
	int N,cs=0,i,ret;
	for(scanf("%d",&N);N--;) {
		scanf("%s",str);
		for(ret=0,i=1;str[i];i++) if (str[i]!=str[i-1]) ret++;
		if (str[i-1]=='-') ret++;
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}
