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

int main(int argc, char *argv[])
{
	char buf[4096];
	FILE *in = stdin;
	int N;

	FGETS(buf, 4096, in);
	sscanf(buf, "%d", &N);
	REP(c,N)
	{
		char s[100];
		s[0] = 0;
int sym[1000];
//memset(sym, 0, sizeof(sym);
for (int i = 0; i < 1000; i++)
{
	sym[i] = -1;
}

//	Data preparaion put here

		FGETS(buf, 4096, in);
		sscanf(buf, "%[^\r\n]", s);
sym[(int)s[0]] = 1;
int sz = strlen(s);
int base = 0;
for (int i = 1; i < sz; i++)
{
	if (sym[(int)s[i]] == -1)
	{
		sym[(int)s[i]] = base;
		base++;
		if (base == 1) base++;
	}
}
if (base < 2) base = 2;

unsigned long long sum = 0;
for (int i = 0; i < sz; i++)
{
	sum *= base;
	sum += sym[(int)s[i]];
}



		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("%llu\n", sum);

	}
	return 0;
}
