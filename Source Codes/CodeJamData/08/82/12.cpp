#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cassert>

using namespace std;

typedef double D;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<D> vd;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

template<typename T> T abs(T x) { return (x>0) ? x : -x; }
template<typename T> T sqr(T x) { return x*x;            }

map<string,int> col;
int ccol;

int getCol(string s) {
	if (col.count(s))
		return col[s];
	col[s]=ccol++;
	return col[s];
}

struct P {
	int l, r;
	P() {}
	P(int l, int r): l(l), r(r) {}
};

bool cmp(P a, P b) {
	return a.l<b.l;
}

const int inf=1<<30;

int n;
vector<P> p[500];

int solve(int c1, int c2, int c3) {
	vector<P> q;
	int tmp;
	for (int i=0; i<sz(p[c1]); i++)
		q.pb(p[c1][i]);
	if (c2!=c1) 
		for (int i=0; i<sz(p[c2]); i++)
			q.pb(p[c2][i]);
	if (c3!=c2)
		for (int i=0; i<sz(p[c3]); i++)
			q.pb(p[c3][i]);
	if (sz(q)==9) {
		tmp=1;
	}
	sort(all(q),&cmp);
	if (sz(q)==0) 
		return inf;
	if (q[0].l!=1) 
		return inf;
	int max_right=q[0].r;
	int right=q[0].r;
	int res=1;
	for (int i=1; i<sz(q); i++) {
		if (q[i].l==right+1)
			max_right=max(max_right,q[i].r);
		if (q[i].l>right) {
			res++;
			right=max_right;
			if (q[i].l>right) {
				if (q[i].l==right+1)
					max_right=max(max_right,q[i].r);
					res++;
					right=max_right;
					if (q[i].l>right)
						return inf;
			}
		}
		max_right=max(max_right,q[i].r);
	}
	if (right!=10000) {
		res++;
		right=max_right;
		if (right!=10000)
			return inf;
	}
	return res;
}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	int tn;
	cin>>tn;
	for (int tst=0; tst<tn; tst++) {
		cerr<<tst<<endl;
		printf("Case #%d: ",tst+1);
		col.clear();
		ccol=0;
		cin>>n;
		for (int i=0; i<n; i++)
			p[i].clear();
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			int c=getCol(s);
			int l,r;
			cin>>l>>r;
			p[c].pb(P(l,r));
		}
		int res=1<<30;
		for (int i=0; i<n; i++)
			for (int j=i; j<n; j++)
				for (int k=j; k<n; k++)
					res=min(res,solve(i,j,k));
		if (res==(1<<30))
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",res);
	}

	return 0;
}
