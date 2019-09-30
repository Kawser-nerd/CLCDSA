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

char s[30];
int set[10];

memset(set, 0, sizeof(set));

//	Data preparaion put here
	FGETS(buf, 4096, in);
	sscanf(buf, "%[0-9]", s);
int sz = strlen(s);
// 123 sz = 3. 0/1/2

int is_done = 0;
for (int j = sz - 2; j >= 0; j--)
{
	int i = j;
	for (int x = j+1; x < sz; x++)
	{
		if (s[x] > s[j]) if (i == j || s[x] < s[i]) { i = x; }
	}

//for (int i = sz-1; i > 0; i--)
//{
//	for (int j = i-1; j >= 0; j--)
//	{
		if (s[i] > s[j])
		{
			int k;
			char tmp = s[i];
			for (k = i; k > j; k--)
			{
				s[k] = s[k-1];
			}
			s[k] = tmp;
			sort(s+j+1, s+sz);
			is_done = 1;
			break;
		}
//	}
	if (is_done) break;
}
if (!is_done)
{	// Add one more digit from scratch
	int p = 0;
//printf("ND:%s %d\n", s, s[p]-'0');
	for (int i = 1; i < sz; i++)
	{
//printf("i=%d s[i]=%d\n", i, s[i]-'0');
		if (s[i] > '0' && s[i] < s[p])
		{
			p = i;
//printf("New P = %d (%d -> %d)\n", p, s[i]-'0', s[p]-'0');
		}
	}
	{	// Put smallest non-zeo at front
		char tmp = s[0]; s[0] = s[p]; s[p] = tmp;
	}
	{	// Put zero in s[1]
		s[sz++] = s[1]; s[1] = '0';
		s[sz] = 0;
	}
	{	// Sort remaining...
		sort(s+2, s+sz);
	}
}

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("%s\n", s);

	}
	return 0;
}
