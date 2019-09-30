// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a);i<_b;++i)
#define ROF(i,b,a) for(int _a=(a),i=(b);i>_a;--i)
#define REP(n) for(int _n=(n);_n--;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define ALL(x) (x).begin(),(x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO(){ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
typedef long long LL;typedef pair<int,int> PII;typedef pair<LL,LL> PLL;
typedef vector<int>VI;typedef vector<LL>VL;typedef vector<PII>VP;
template<class A,class B>inline bool mina(A &x,const B &y){return(y<x)?(x=y,1):0;}
template<class A,class B>inline bool maxa(A &x,const B &y){return(x<y)?(x=y,1):0;}

#define MAXN (1004)

int main()
{
	IO();
	cint1(TT);
	FOR(T,1,TT+1)
	{
		LL N, K;
		cin >> N >> K;

		map<LL,LL> C;
		MAX_PQ(LL) Q;
		auto add = [&](LL l, LL n)
		{
			if(C.find(l) == C.end())
			{
				C[l] = n;
				Q.push(l);
			}
			else C[l] += n;
		};

		LL sol = 0;
		add(N, 1);
		while(1)
		{
			LL l = Q.top();
			Q.pop();

			LL n = C[l];
			C.erase(l);

			K -= n;
			if(K <= 0)
			{
				sol = l;
				break;
			}

			if(l % 2 == 0)
			{
				add(l/2, n);
				add(l/2 - 1, n);
			}
			else add(l/2, 2*n);
		}

		cout << "Case #" << T << ": " << sol/2 << ' ' << (sol-1)/2 << nl;
	}

	return 0;
}