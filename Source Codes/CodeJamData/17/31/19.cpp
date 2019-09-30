#include <cstdio>
#include <algorithm>
#define LL long long

using namespace std;

const double pi = 3.1415926535897932384626433832795;

struct pan
{
	LL R, H, S;
}P[1010], Q[1010];

bool cmpR(pan a, pan b)
{
	return a.R < b.R;
}

bool cmpS(pan a, pan b)
{
	return a.S > b.S;
}

int main()
{
	int T, N, K;
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for (int _T = 1; _T <= T; _T++)
	{
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++)
		{
			scanf("%lld%lld", &P[i].R, &P[i].H);
			P[i].S = P[i].R * P[i].H * (LL)(2);
		}
		sort(P, P + N, cmpR);
		
		LL ans = 0;
		for (int i = K - 1; i < N; i++)
		{
			LL S0 = P[i].R * P[i].R + P[i].S;
			for (int j = 0; j < i; j++) Q[j] = P[j];
			sort(Q, Q + i, cmpS);
			for (int j = 0; j < K - 1; j++) S0 += Q[j].S;
			ans = max(ans, S0);
		}
		printf("Case #%d: %.10lf\n", _T, pi * ans);
	}
	return 0;
}
