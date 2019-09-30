#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define bit(x,i) ((x>>i)&1)
#define N 30

ll work()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	ll ans = 0;
	rep(i, N) if(bit(a, i))
	rep(j, N) if(bit(b, j))
	rep(k, N) if(bit(c, k))
	{
		ll ways = 1;
		//printf("i: %d, j: %d, k: %d\n", i, j, k);
		rep(l, N)
		{
			//printf("l: %d\n", l);
			int aok = 0;
			if(l < N - i - 1) aok = 1 << bit(a, N - l - 1);
			else if(l == N - i - 1) aok = 1;
			else aok = 3;

			int bok = 0;
			if(l < N - j - 1) bok = 1 << bit(b, N - l - 1);
			else if(l == N - j - 1) bok = 1;
			else bok = 3;

			int cok = 0;
			if(l < N - k - 1) cok = 1 << bit(c, N - l - 1);
			else if(l == N - k - 1) cok = 1;
			else cok = 3;

			int coeff = 0;
			//printf("aok: %d, bok: %d, cok: %d\n", aok, bok, cok);
			rep(ab, 2) if(bit(aok, ab))
			rep(bb, 2) if(bit(bok, bb))
			rep(cb, 2) if(bit(cok, cb))
			{
			//printf("ab: %d, bb: %d, cb: %d, and: \n", ab, bb, cb, ab & bb);
			if((ab & bb) == cb)
				coeff++;
			}
			//printf("%d\n", coeff);
			ways *= coeff;
		}
		//printf("ways: %lld\n", ways);
		ans += ways;
	}
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, n) printf("Case #%d: %lld\n", i + 1, work());
	return 0;
}
