#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

pair<Int, Int> A[256];
Int P[256];
Int C[256];

Int G(Int m, Int f, int n, Int cnt)
{
	Int sum = 0;
	Int price = f*cnt;
	if(price > m)
		return 0;
	
	int i;
	FOR(i, 0, n)
	{
		if((m - price)/P[i]/cnt < C[i])
			return sum + (m - price)/P[i];

		sum += C[i]*cnt;
		price += P[i]*C[i]*cnt;
	}

	return sum;
}

Int G(Int m, Int f, int n)
{
	Int sum = 0;
	Int price = f;
	
	int i;
	FOR(i, 0, n)
	{
		if(sum != 0 && price/sum < P[i])
			break;

		if((m - price)/P[i] < C[i])
			return sum + (m - price)/P[i];

		sum += C[i];
		price += P[i]*C[i];
	}

	return max(G(m, f, n, m/price), G(m, f, n, m/price + 1));
/*
	Int pos = i;
	Int cnt = m/price;
	Int len = sum;
	Int res = 0;

	m %= price;

	sum = 0;
	price = f;
	FOR(i, 0, n)
	{
		if((m - price)/P[i] < C[i])
		{
			res = cnt*len + (m - price)/P[i];
			break;
		}

		sum += C[i];
		price += P[i]*C[i];
	}

	sum = 0;
	FOR(i, pos, n)
	{
		if(((m - price)/P[i])/cnt < C[i])
		{
			sum += (m - price)/P[i];
			break;
		}

		sum += C[i]*cnt;
		price += P[i]*C[i]*cnt;
	}

	res = max(res, cnt*len + sum);
	return res;
*/}

int SolveTest(int test)
{
	Int M, F;
	int N;
	scanf("%lld%lld%d", &M, &F, &N);

	int i;
	FOR(i, 0, N)
		scanf("%lld%lld", &A[i].first, &A[i].second);

	sort(A, A + N);

	Int prev = 0;
	int cnt = 0;
	FOR(i, 1, N + 1)
		if(i == N || A[i].first != A[i - 1].first)
		{
			if(A[i - 1].second >= prev)
			{
				P[cnt] = A[i - 1].first;
				Int t = A[i - 1].second + 1;
				C[cnt] = t - prev;					
				prev = t;
				++cnt;
			}
		}

	printf("Case #%d: %lld\n", test + 1, G(M, F, cnt));
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
