#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 1000010
#define LL long long

using namespace std;

int tt;
int n,d,n0;
int s0,as,cs,rs;
int m0,am,cm,rm;
int s[maxn],m[maxn];
vector<int> lis[maxn];
vector<int> g[maxn];
int a[maxn];
bool used[maxn];
int ans,cur;

void add(int l,int r,int x) {
	if (s[x]<l || s[x]>r) return;
	if (used[x]) return;
	used[x]=true;
	cur++;
	for (int i=0;i<(int)g[x].size();++i)
		add(l,r,g[x][i]);
}

void del(int x) {
	if (!used[x]) return;
	used[x]=false;
	cur--;
	for (int i=0;i<(int)g[x].size();++i)
		del(g[x][i]);
}

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&n,&d);

		scanf("%d%d%d%d",&s0,&as,&cs,&rs);
		scanf("%d%d%d%d",&m0,&am,&cm,&rm);
		s[0]=s0; a[0]=s[0];
		m[0]=m0;
		for (int i=1;i<n;++i) {
			s[i]=((LL)s[i-1]*as+cs)%rs;
			a[i]=s[i];
			m[i]=((LL)m[i-1]*am+cm)%rm;
		}
		for (int i=1;i<n;++i)
			m[i]%=i;
		sort(a,a+n);
		n0=unique(a,a+n)-a;
		for (int i=0;i<=1000000;++i) lis[i].clear();
		for (int i=0;i<n;++i)
			lis[s[i]].push_back(i);

		memset(used,false,sizeof(used));
		for (int i=0;i<n;++i) g[i].clear();
		for (int i=1;i<n;++i)
			g[m[i]].push_back(i);

		ans=0,cur=0;
		int las=-1;
		for (int i=0;i<n0;++i) {
			while (las+1<n0 && a[las+1]-a[i]<=d) {
				++las;
				for (int j=0;j<(int)lis[a[las]].size();++j)
					if (lis[a[las]][j]==0 || used[m[lis[a[las]][j]]])
						add(a[i],a[las],lis[a[las]][j]);
			}
			ans=max(ans,cur);
			for (int j=0;j<(int)lis[a[i]].size();++j)
				del(lis[a[i]][j]);
		}

		printf("Case #%d: %d\n",ii,ans);
	}

}
