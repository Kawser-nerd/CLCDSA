#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


long long ans=0;
int used[300];
int a[100];
int tr[300];
char buf[100];

int main()
{
	int v=0,V;
	int n,i,cur,base;

	for(scanf("%d\n",&V);V;V--) {
		v++;
		printf("Case #%d: ",v);

		gets(buf);
		n=strlen(buf);
		memset(used,0,sizeof(used));
		cur=1;
		for(i=0;i<n;i++) {
			if (!used[buf[i]]) {
				a[i]=cur;
				tr[buf[i]]=cur;
				if (cur==1) cur=0;
				else if (cur==0) cur=2;
				else cur++;
				used[buf[i]]=1;
			}
			else a[i]=tr[buf[i]];
		}

		if (cur==0) base=2;
		else base=cur;
		ans=0;
		for(i=0;i<n;i++) ans=ans*base+a[i];

		printf("%lld\n",ans);
	}
}
				
