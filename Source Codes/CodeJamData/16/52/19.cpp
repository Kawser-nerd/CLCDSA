#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int tt;
int n,m;
string s,s1;
int pp;
int a[110];
int size[110];
int cnt,sum;
int cur[110];

int choose() {
	int x=rand()%n;
	while (cur[x+1]!=0) x=rand()%n;
	while (cur[a[x]]==0) x=a[x]-1;
	return x;
}

void gen() {
	for (int i=1;i<=n;++i) cur[i]=0;
	cur[0]=1;
	string res;
	sum++;
	for (int i=0;i<n;++i) {
		int x=choose();
		cur[x+1]=1;
		res+=s[x];
		if (i+1>=pp)
			if (res.substr(i-pp+1,pp)==s1) {
				cnt++;
				return;
			}
	}
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);

		scanf("\n");
		cin >> s;
		scanf("%d\n",&m);
		printf("Case #%d:",ii);
		for (int i=0;i<m;++i) {
			cin >> s1; pp=s1.size();
			cnt=0; sum=0;
			for (int j=0;j<10000;++j)
				gen();
			//printf(" %.6f %.6f",cnt,sum);
			printf(" %.10f",(double)cnt/(double)sum);
		}
		printf("\n");
	}
}