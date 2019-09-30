#include<stdio.h>
#include<string.h>

char str[32];

int main() {
	int N,cs=0,n,i;
	long long r;
	for(scanf("%d",&N);N--;) {
		scanf("%s",str);
		n=strlen(str);
		for(i=0;i<n-1;i++) if (str[i]>str[i+1]) {
			while(i>0 && str[i]==str[i-1]) i--;
			str[i]--;
			for(i++;i<n;i++) str[i]='9';
		}
		sscanf(str,"%I64d",&r);
		printf("Case #%d: %I64d\n",++cs,r);
	}
	return 0;
}