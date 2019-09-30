#include<stdio.h>
#include<string.h>

char str[1024];
int n,m;

int main() {
	int i,j,N,cs=0,ret;
	for(scanf("%d",&N);N--;) {
		scanf("%s %d",str,&m);
		n=strlen(str);
		for(ret=i=0;i<=n-m;i++) if (str[i]=='-') {
			for(j=0;j<m;j++) if (str[i+j]=='-') str[i+j]='+'; else str[i+j]='-';
			ret++;
		}
		for(i=0;i<m;i++) if (str[n-m+i]=='-') ret=-1;
		if (ret==-1) printf("Case #%d: IMPOSSIBLE\n",++cs);
		else printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}