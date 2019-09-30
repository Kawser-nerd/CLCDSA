#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

long long A,B,K;
long long cnt[32][2][2][2];

int nxt(int p, int a)
{
	if (p == 0 && a == 0) return 0;
	if (p == 1 && a == 0) return 1;
	if (p == 0 && a == 1) return -1;
	return 0;
}

long long go(int l, int p, int q, int r)
{
	if (l == -1) return 1;
	if (cnt[l][p][q][r] != -1) return cnt[l][p][q][r];
	long long &res = cnt[l][p][q][r];
	res = 0;
	for (int a=0;a<2;a++) for (int b=0;b<2;b++){
		int c = a & b, np = p?1:nxt((A&(1ll<<l))>0,a), nq = q?1:nxt((B&(1ll<<l))>0,b), nr = r?1:nxt((K&(1ll<<l))>0,c);
		if (np == -1 || nq == -1 || nr == -1) continue;
		res += go(l-1,np,nq,nr);
	}
	return res;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test);
	for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		scanf ("%lld %lld %lld",&A,&B,&K); A--; B--; K--;
		memset(cnt,-1,sizeof(cnt));

		printf ("%lld\n",go(31,0,0,0));
	}

	return 0;
}