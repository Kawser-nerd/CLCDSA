#include <stdio.h>

int n,r,y,b;
int o,g,v;
char s[1010];

int btr(int at,int r,int y,int b) {
	if(at==n) return s[n-1]!=s[0];
	if(r && s[at-1]!='R') {
		s[at]='R';
		if(btr(at+1,r-1,y,b)) return 1;
	}
	if(y && s[at-1]!='Y') {
		s[at]='Y';
		if(btr(at+1,r,y-1,b)) return 1;
	}
	if(b && s[at-1]!='B') {
		s[at]='B';
		if(btr(at+1,r,y,b-1)) return 1;
	}
	return 0;
}

void solve() {
	int i;
	int has;
	char best;
	scanf("%d %d %d %d %d %d %d",&n,&r,&o,&y,&g,&b,&v);
	if(o+g+v>0) { printf("sanity error\n"); return; }
	s[n]=0;
	for(i=0;i<n-10 || i<1;i++) {
		has=-1;
		best=' ';
		if(r>=has && r && (!i || s[i-1]!='R')) has=r,best='R';
		if(y>=has && y && (!i || s[i-1]!='Y')) has=y,best='Y';
		if(b>=has && b && (!i || s[i-1]!='B')) has=b,best='B';
		if(best==' ') goto feil;
		s[i]=best;
		if(best=='R') r--;
		else if(best=='Y') y--;
		else if(best=='B') b--;
	}
	if(btr(i,r,y,b)) {
		for(i=0;i<n;i++) if(s[i]==s[(i+1)%n]) printf("error");
		puts(s);
	}
	else {
	feil:
		puts("IMPOSSIBLE");
	}
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
