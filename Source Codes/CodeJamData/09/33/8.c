#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define FGETS(s,n,p)	s[0] = 0; fgets(s,n,p)
#define FOR(i,a,b)	for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i,a,b)	for (int i(a), _b(b); i >= _b; --i)
#define REP(i,n)	for (int i(0), _n(n); i < _n; ++i)
#define REPD(i,n)	for (int i((n)-1); i >= 0; --i)
#define FILL(a,c)	memset(&a, c, sizeof(a))

typedef unsigned long long	ull;
typedef long long		ll;

template<typename T> void remin(T& a, const T& b) { if (b < a) a = b; }
template<typename T> void remax(T& a, const T& b) { if (b > a) a = b; }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }

int solve(int P, int Q, int *seq, int *cell)
{
	int sum = 0;
	int pos = *seq;
//printf("%d pos = %d\n", P, pos);
	for (int i = pos - 1; i > 0; i--)
	{
		if (cell[i] == 1)
		{
			sum++;
		}
		else
		{
			break;
		}
	}
//printf("sum = %d\n", sum);
	for (int i = pos + 1; i <= P; i++)
	{
//printf("i = %d\n", i);
		if (cell[i] == 1)
		{
			sum++;
		}
		else
		{
			break;
		}
	}
//printf("sum = %d\n", sum);
	cell[pos] = 0;

	if (Q > 1)
	{
		sum += solve(P, Q-1, seq+1, cell);
	}

	return sum;
}
int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int N;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	REP(c,N)
	{
//	Data preparaion put here
		int P, Q;
		int seq[120];
		fscanf(in, "%d %d", &P, &Q);
		for (int i = 0; i < Q; i++)
		{
			fscanf(in, "%d", &(seq[i]));
		}

		int sum = 10000000;
		do
		{
/*
for (int i = 0; i < Q; i++)
{
	printf(" %d", seq[i]);
}
printf("\n");
*/
int cell[10010];
memset(cell, 0, sizeof(cell));
for (int i = 0; i <= P; i++)
{
	cell[i] = 1;
}
			int v = solve(P, Q, seq, cell);
			if (v < sum) sum = v;
		} while (next_permutation(seq, seq+Q));


		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
	printf("%d\n", sum);

	}
	return 0;
}
