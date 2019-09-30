#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int x,val;
};

int tt,n;
int ff[1010],gg[1010];
node a[1010];

bool cmp(const node &a,const node &b) {
	return a.x>b.x;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);

		for (int i=0;i<n;++i) {
			scanf("%d",&a[i].x);
			a[i].val=0;
		}
		for (int i=0;i<n;++i)
			for (int j=0;j<i;++j)
				if (a[j].x>a[i].x) a[i].val++;

		sort(a,a+n,cmp);

		int res=0;
		for (int i=1;i<n;++i)
			res+=min(i-a[i].val,a[i].val);

		printf("Case #%d: %d\n",ii,res);
	}
}

