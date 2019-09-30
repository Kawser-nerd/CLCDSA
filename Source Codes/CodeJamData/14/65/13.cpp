#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#define LL long long

using namespace std;

int tt;
LL n;
int a,b;
int m;

struct matrix {
	LL c[120][120];
};

matrix mat,mat1,now;

matrix operator *(matrix &a,matrix &b) {
	matrix c;
	memset(c.c,0,sizeof(c.c));
	for (int i=0;i<m;++i)
		for (int j=0;j<m;++j)
			for (int k=0;k<m;++k)
				c.c[i][j]+=a.c[i][k]*b.c[k][j];
	return c;
}

LL col[120];

LL ff[10000];

int main() {
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		cin >> n >> a >> b;
		for (int i=0;i<a;++i)
			ff[i]=1;
		for (int i=a;i<b;++i)
			ff[i]=ff[i-a]+1;
		for (int i=b;;++i) {
			ff[i]=ff[i-b]+ff[i-a];
			if (ff[i]>=n) break;
		}

		int ans=0;
		for (int i=0;;++i)
			if (ff[i]>=n) {
				ans=i;
				break;
			}

		printf("Case #%d: %d\n",ii,ans);

		/*
		m=b;
		memset(mat.c,0,sizeof(mat.c));

		for (int i=0;i<m-1;++i)
			mat.c[i][i+1]=1;
		mat.c[m-1][0]=1;
		mat.c[m-1][b-a]+=1;
		for (int i=0;i<a;++i)
			col[i]=1;
		for (int i=a;i<m;++i)
			col[i]=col[i-a]+1;

		printf("Case #%d: ",ii);
		bool ff=false;
		for (int i=0;i<m;++i)
			if (col[i]>=n) {
				cout << i << endl;
				ff=true;
				break;
			}
		if (ff) continue;

		int up;
		mat1=mat;
		for (int i=0;i<=62;++i) {
			LL cur=0;
			bool flag=false;
			for (int j=0;j<m;++j) {
				cur+=mat1.c[m-1][j]*col[j];
				if (cur>=n) {
					flag=true;
					break;
				}
			}
			if (flag) {
				up=i;
				break;
			}
			mat1=mat1*mat1;
		}
		if (up==0) {
			cout << b << endl;
			//cout << "!!" << endl;
			continue;
		}
		up--;
		LL ans=b-1;
		ans+=(LL)1<<(LL)up;
		mat1=mat;
		for (int i=0;i<up;++i)
			mat1=mat1*mat1;
		now=mat1;
		for (int i=up-1;i>=0;--i) {
			mat1=mat;
			for (int j=0;j<i;++j)
				mat1=mat1*mat1;

			mat1=now*mat1;
			bool flag=false;
			LL cur=0;
			for (int j=0;j<m;++j) {
				cur+=mat1.c[m-1][j]*col[j];
				if (cur>=n) {
					flag=true;
					break;
				}
			}
			if (!flag) {
				now=mat1;
				ans+=(LL)1<<(LL)i;
			}
		}
		cout << ans+1 << endl;
		*/
	}

}
