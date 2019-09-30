#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

int tt;
int n;
int a[2010][2010];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d\n",&n);
		for (int i=0;i<2*n;++i) {
			for (int j=0;j<2*n;++j) {
				char ch;
				scanf("%c",&ch);
				if (ch=='1') a[i][j]=1;
				else a[i][j]=0;
			}
			scanf("\n");
		}

		bool flag=true;
		int ans=0;
		int p=0,q=0;
		for (int i=0;i<2*n;++i) {
			if (i==0) {
				int cc=0;
				for (int j=0;j<2*n;++j)
					cc+=a[i][j];
				if (cc!=n) {
					flag=false;
					break;
				}
			}
			for (int j=0;j<2*n;++j)
				if ((a[i][j]==a[0][j])!=(a[i][0]==a[0][0])) {
					flag=false;
					break;
				}
			if ((a[i][0]==a[0][0])^(i&1)) p++;
			else q++;
		}
		ans+=min(p,q)/2;
		p=0,q=0;
		for (int j=0;j<2*n;++j) {
			if (j==0) {
				int cc=0;
				for (int i=0;i<2*n;++i)
					cc+=a[i][j];
				if (cc!=n) {
					flag=false;
					break;
				}
			}
			for (int i=0;i<2*n;++i)
				if ((a[i][j]==a[i][0])!=(a[0][j]==a[0][0])) {
					flag=false;
					break;
				}
			if ((a[0][j]==a[0][0])^(j&1)) p++;
			else q++;
		}
		ans+=min(p,q)/2;

		printf("Case #%d: ",ii);
		if (flag) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}

}
