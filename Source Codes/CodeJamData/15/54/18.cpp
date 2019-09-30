#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define LL long long

using namespace std;

vector<pair<LL,LL> > f;
vector<pair<LL,LL> > g,h;
LL aa[10010];
LL bb[10010];
int tt;
int n;
vector<LL> ans;

bool check(int x) {
	g.clear();
	if (x==0) {
		for (int i=0;i<(int)f.size();++i)
			if (f[i].se%2==0) {
				g.push_back(mp(f[i].fi,f[i].se/2));
			} else return false;
		return true;
	}
	h.clear(); h=f;
	int p=abs(x);
	int j=0;
	for (int i=0;i<(int)h.size();++i) {
		if (h[i].se==0) continue;
		while (j<(int)h.size() && h[j].fi!=h[i].fi+p) ++j;
		if (j==(int)h.size()) return false;
		if (h[j].se<h[i].se) return false;
		if (x<0) g.push_back(mp(h[j].fi,h[i].se));
		else g.push_back(mp(h[i].fi,h[i].se));
		h[j].se-=h[i].se; h[i].se=0;
	}
	for (int i=0;i<(int)g.size();++i)
		if (g[i].fi==0) return true;
	return false;
}

void solve(int dep) {
	if (f.size()==1 && f[0].se==1) return;
	for (int i=0;i<(int)f.size();++i)
		if (check(f[i].fi)) {
			ans.push_back(f[i].fi);
			f=g;
			solve(dep+1);
			return;
		}
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%I64d",&aa[i]);
		for (int i=0;i<n;++i)
			scanf("%I64d",&bb[i]);
		f.clear();
		for (int i=0;i<n;++i) {
			f.push_back(mp(aa[i],bb[i]));
		}

		sort(f.begin(),f.end());

		ans.clear();
		solve(0);
		printf("Case #%d:",ii);
		for (int i=0;i<(int)ans.size();++i)
			cout << " " << ans[i];
		printf("\n");
	}

}
