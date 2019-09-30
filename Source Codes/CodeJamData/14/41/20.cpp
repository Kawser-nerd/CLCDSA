#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

int tt,n,m;
int a[10010];
multiset<int> f;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&n,&m);

		for (int i=0;i<n;++i) {
			int x;
			scanf("%d",&x);
			f.insert(x);
		}
		int ans=0;
		while (!f.empty()) {
			int x=*(--f.end());
			f.erase(--f.end());
			ans++;
			if (!f.empty()) {
				multiset<int>::iterator it=f.upper_bound(m-x);
				if (it!=f.begin())
					f.erase(--it);
			}
		}

		printf("Case #%d: %d\n",ii,ans);
	}
}
