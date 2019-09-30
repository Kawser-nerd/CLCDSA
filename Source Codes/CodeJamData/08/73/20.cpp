#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
#define FR(i,a,n) for(int (i) = (a); (i) < (n); (i)++)
#define FOR(i,n) FR(i,0,n)
#define RF(i,a,n) for(int (i) = int(n)-1; (i) >= (a); (i)--)
#define ROF(i,n) RF(i,0,n)
typedef long double ld;
typedef long long ll;
int Q;
ld pr[30][4];
set<ll> done;
struct State
{
	ld p;
	ll st;
	bool operator<(const State& o) const
	{
		return p<o.p;
	}
};
priority_queue<State> PQ;

void printstate(State& cur)
{
	printf("PROB: %Lf\n", cur.p);
	FOR(i,Q)
	{
		printf(" %d", (cur.st>>(2*i))&3);
	}
	printf("\n");
}

void calcProb(State& cur)
{
	cur.p = 1;
	FOR(i,Q)
	{
		cur.p*=pr[i][(cur.st>>(2*i))&3];
	}
}
int main()
{
	int TESTS;
	scanf("%d", &TESTS);
	FOR(tests,TESTS)
	{
		int M;
		scanf("%d%d", &M, &Q);
		done.clear();
		while(PQ.size())
			PQ.pop();
		long long dif = 1<<Q;
		dif*=dif;
		FOR(i,Q)
		{
			FOR(p,4)
				scanf("%Lf", pr[i]+p);
			sort(pr[i], pr[i]+4);
		}
		if(dif<=M)
		{
			printf("Case #%d: 1.0\n", tests+1);
			continue;
		}
		State cur;
		cur.p = 1;
		cur.st = 0;
		FOR(i,Q)
		{
			cur.p*=pr[i][3];
			cur.st|=3LL<<(2*i);
		}
		PQ.push(cur);
		ld res = 0;
		while(M!=0)
		{
			cur = PQ.top();
			PQ.pop();
			if(done.count(cur.st))
				continue;
			M--;
			done.insert(cur.st);
			res+=cur.p;
			printf("%Lf\n", cur.p);
			FOR(i,Q)
			{
				int num = (cur.st>>(2*i))&3;
				if(num==0)
					continue;
				State next;
				next.st = cur.st-(1LL<<(2*i));
				calcProb(next);
				PQ.push(next);
			}
		}
		printf("Case #%d: %.9Lf\n", tests+1, res);
	}
	return 0;
}
