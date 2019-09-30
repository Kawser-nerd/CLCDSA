#include <stdio.h>
#include <string.h>

int n;
char s[1000][22];
char t[1000][22];

void solve() {
	int i,mask,best=0,j,bc;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s %s",s[i],t[i]);
	for(mask=0;mask<(1<<n);mask++) {
		for(bc=i=0;i<n;i++) if(mask&(1<<i)) bc++;
		if(best>bc) continue;
		/* each word in mask must occur outside mask */
		for(i=0;i<n;i++) if(mask&(1<<i)) {
			for(j=0;j<n;j++) if(!(mask&(1<<j))) {
				if(!strcmp(s[i],s[j])) goto sok;
			}
			goto fail;
		sok:
			for(j=0;j<n;j++) if(!(mask&(1<<j))) {
				if(!strcmp(t[i],t[j])) goto tok;
			}
			goto fail;
		tok:;
		}
		best=bc;
	fail:;
	}
	printf("%d\n",best);
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
