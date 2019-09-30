#include <bits/stdc++.h>
using namespace std;

int n;
char s[1013];
bool has[1013];

void solve() {
	memset(has,0,sizeof has);
	scanf(" %s",&s);
	n = strlen(s);
	reverse(s,s+n);
	string ans;
	int on = 0;
	while (on<n) {
		for (int i=on;i<n;i++) if (s[i]>s[on]) on = i;
		ans+=s[on];
		has[on] = 1;
		on+=1;
	}
	for (int i=n-1;i>=0;i--) if (!has[i]) ans+=s[i];
	printf("%s\n",ans.c_str());
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
