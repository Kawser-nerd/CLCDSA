#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int tt;
int n,m;
int maxi[110],mini[110],cur[110];
int s[1010];

bool check(int l,int r) {
	int cc=r/m;
	if (r<0 && r%m!=0) cc--;
	return cc*m>=l && cc*m<=r;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n-m;++i)
			scanf("%d",&s[i]);

		printf("Case #%d: ",ii);
		if (n==m) {
			if (s[0]%m==0) puts("0");
			else puts("1");
			continue;
		}

		memset(maxi,0,sizeof(maxi));
		memset(mini,0,sizeof(mini));
		memset(cur,0,sizeof(cur));

		for (int i=0;i<n-m;++i) {
			int p=s[i+1]-s[i];
			cur[i%m]+=p;
			maxi[i%m]=max(maxi[i%m],cur[i%m]);
			mini[i%m]=min(mini[i%m],cur[i%m]);
		}

		int ans=0;
		for (int i=0;i<m;++i)
			ans=max(ans,maxi[i]-mini[i]);

		bool flag=false;
		for (int i=0;i<=n;++i) {
			int l=0,r=0;
			for (int j=1;j<m;++j) {
				l+=min(mini[0]-mini[j],maxi[0]-maxi[j])-i;
				r+=max(mini[0]-mini[j],maxi[0]-maxi[j])+i;
			}
			l-=s[0],r-=s[0];
			if (check(l,r)) {
				ans+=i;
				flag=true;
				break;
			}
		}
		printf("%d\n",ans);
		if (!flag) puts("Error!");
	}

}
