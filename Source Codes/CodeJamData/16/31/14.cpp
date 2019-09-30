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
#include<functional>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;
typedef pair<int, char> pci;
typedef vector<pci> vpci;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
//#define LL "%lld"
#define RLL(x) scanf(LL,&(x))



void test(int T)
{
	vpci v;
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		int t;
		cin>>t;
		v.push_back(pci(t, 'A' + i));
	}
	v.push_back(pci(0, 'Z'+1));
	v.push_back(pci(0, 'Z'+1));
	sort(v.begin(), v.end(), greater<pci>());
	printf("Case #%d:", T);
	while(v[0].first > 0)
	{
		if(v[0].first > v[1].first || (v[0].first == v[2].first))
		{
			printf(" %c", v[0].second);
			--v[0].first;
		}
		else
		{
			printf(" %c%c", v[0].second, v[1].second);
			--v[0].first;
			--v[1].first;
		}
		sort(v.begin(), v.end(), greater<pci>());
	}
	printf("\n");
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		test(i+1);
    return 0;
}