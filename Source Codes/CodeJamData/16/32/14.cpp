#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
//#define LL "%lld"
#define RLL(x) scanf(LL,&(x))

char res[100][100];

void buildTable(ll b, ll m)
{
	cl(res);
	for(int i = 0; i < b; ++i)
		for(int j = 0; j < b; ++j)
			if(j > i)
				res[i][j] = '1';
			else
				res[i][j] = '0';
	if(1LL<<(b-2) == m)
		return;
	res[0][b-1] = '0';
	int pos = b-2;
	while(pos >= 0)
	{
		res[0][pos] = (m&1) + '0';
		m>>=1;
		--pos;
	}
}

void test(int T)
{
	ll b,m;
	cin>>b>>m;
	if(1LL<<(b-2) < m)
	{
		printf("Case #%d: IMPOSSIBLE\n", T);
		return;
	}
	printf("Case #%d: POSSIBLE\n", T);
	buildTable(b, m);
	for(int i = 0; i < b; ++i)
		printf("%s\n", res[i]);
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		test(i+1);
    return 0;
}