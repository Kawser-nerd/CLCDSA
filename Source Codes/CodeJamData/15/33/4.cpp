#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase < t; testcase++)
	{
		ll c, d, v;
		scanf("%lld %lld %lld",&c,&d,&v);
		vector<ll> coin(d);
		for(int i=0; i<d; i++)scanf("%lld",&coin[i]);
		coin.push_back(inf);
		int cur = 0;
		ll can_pay = 0;
		int res = 0;
		while(can_pay < v)
		{
			if(coin[cur] <= can_pay+1)
			{
				can_pay += coin[cur] * c;
				cur++;
			}
			else
			{
				ll ncoin = can_pay+1;
				can_pay += ncoin*c;
				res++;
			}
		}
		printf("Case #%d: %d\n",testcase+1, res);
	}
	return 0;
}