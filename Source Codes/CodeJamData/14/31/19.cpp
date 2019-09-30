#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

int T;
ll P, Q;

ll gcd(ll a, ll b)
{
	while(b != 0)
	{
		ll t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		scanf("%I64d/%I64d", &P, &Q);

		ll g = gcd(P, Q);
		P /= g;
		Q /= g;

//		printf("[Q %I64d %I64d]\n", Q, Q & -Q);

		printf("Case #%d: ", TT);

		if(Q != (Q & -Q))
			printf("impossible\n");
		else
		{
			int p = -1;
			int q = -1;
			while(Q > 0)
			{
				Q >>= 1;
				++q;
			}
			while(P > 0)
			{
				P >>= 1;
				++p;
			}

			printf("%d\n", q - p);
		}
	}

	return 0;
}
