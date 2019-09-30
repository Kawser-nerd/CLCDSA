#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
#define LL long long

using namespace std;

struct node {
	bool flag;
	int c[26];
};

int tt;
int n,m,tot;
string s[1000];
int f[200000];
int ff[200000];
int size[200000];
node a[200000];
int fac[2000];
int res,ans;

int pow(int a,int b) {
	int res=1;
	for (int i=0;i<=30;++i) {
		if ((b>>i)&1) res=(LL)res*(LL)a%MOD;
		a=(LL)a*(LL)a%MOD;
	}
	return res;
}

void cons() {
	tot=1;
	a[0].flag=false;
	memset(a[0].c,0,sizeof(a[0].c));
	for (int i=0;i<n;++i) {
		int tmp=0;
		for (int j=0;j<(int)s[i].size();++j) {
			if (a[tmp].c[s[i][j]-'A']==0) {
				memset(a[tot].c,0,sizeof(a[tot].c));
				a[tot].flag=false;
				a[tmp].c[s[i][j]-'A']=tot++;
			}
			tmp=a[tmp].c[s[i][j]-'A'];
		}
		a[tmp].flag=true;
	}
}

bool cmp(int x,int y) {
	return size[x]>size[y];
}

int go(int m,int k) {
	return (LL)fac[m]*(LL)pow(fac[m-k],MOD-2) % MOD;
}

int c(int n,int m) {
	return (LL)fac[n]*(LL)pow(fac[n-m],MOD-2) % MOD *(LL)pow(fac[m],MOD-2) % MOD;
}

int solve(vector<int> &f,int x) {
	int res=1;
	for (int i=0;i<(int)f.size();++i)
		if (size[f[i]]>x) return 0;
		else {
			res=(LL)go(x,size[f[i]])*(LL)res % MOD;
		}
	res=(LL)res*(LL)c(m,x)%MOD;
	return res;
}

void dp(int x) {
	if (a[x].flag) size[x]=1;
	for (int i=0;i<26;++i)
		if (a[x].c[i]!=0) {
			dp(a[x].c[i]);
			size[x]+=size[a[x].c[i]];
		}
	vector<int> son;
	son.clear();
	for (int i=0;i<26;++i)
		if (a[x].c[i]!=0)
			son.push_back(a[x].c[i]);

	if (a[x].flag) son.push_back(tot);

	sort(son.begin(),son.end(),cmp);
	res+=min(m,size[x]);
	if (size[x]>=m) {
		if (son.size()>0 && size[son[0]]>=m) {
			f[x]=1;
			for (int i=0;i<(int)son.size();++i)
				if (size[son[i]]>=m) f[x]=(LL)f[x]*(LL)f[son[i]]%MOD;
				else f[x]=(LL)f[x]*(LL)go(m,size[son[i]])%MOD;
		} else {
			f[x]=0;
			int res=0;
			for (int mode=1,i=m;i>=1;--i,mode*=-1) {
				res=((LL)res+(LL)mode*(LL)solve(son,i)%MOD)%MOD;
			}
			if (res<0) res+=MOD;
			f[x]=res;
		}
	}
}

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	fac[0]=1;
	for (int i=1;i<=1000;++i)
		fac[i]=(LL)fac[i-1]*(LL)i %MOD;

	cin >> tt;
	for (int ii=1;ii<=tt;++ii) {
		cin >> n >> m;

		for (int i=0;i<n;++i)
			cin >> s[i];

		cons();
		memset(size,0,sizeof(size));
		res=0;
		size[tot]=1;
		dp(0);
		if (size[0]<m) ans=(LL)fac[m]*(LL)go(m,size[0])%MOD;
		else ans=f[0];
		if (m==1) ans=1;

		printf("Case #%d: %d %d",ii,res,ans);
		puts("");
	}
}



