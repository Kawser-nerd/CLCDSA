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

typedef struct {
	double v;
	char feat[10];
} tree_type;

int parse_text(char *t, int p, tree_type *tree, int tree_ptr)
{
	int len;
	// Get "("
	while (t[p] != '(') p++;
	p++;	// No more (
	sscanf(t+p, "%lf%n", &(tree[tree_ptr].v), &len);
//printf("%d Read V %lf\n", tree_ptr, tree[tree_ptr].v);
	p+=len;
	while (t[p] == ' ') p++;
	if (t[p] != ')')
	{
		sscanf(t+p, "%s%n", tree[tree_ptr].feat, &len);
//printf("%d Read F %s\n", tree_ptr, tree[tree_ptr].feat);
		p+=len;
		p = parse_text(t, p, tree, tree_ptr*2+1);
		p = parse_text(t, p, tree, tree_ptr*2+2);
	}
	while (t[p] == ' ') p++;
	p++;	// Last ')'
	return p;
}

tree_type tree[1000000];
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
		int L;
		char t[10240];	// t = TEXT
		int A;
		int featz;
		char feat[20][20];

		memset(t, 0, sizeof(t));
		FGETS(buf, 4096, in);
		sscanf(buf, "%d", &L);
		for (int i = 0; i < L; i++)
		{
			FGETS(buf, 4096, in);
//printf("[%s]\n", buf);
			sscanf(buf, "%[^\r\n]", t+strlen(t));
		}

//printf("Text = [%s]\n", t);
//return 0;
// Parse t here!
memset(tree, 0, sizeof(tree));
parse_text(t, 0, tree, 0);

if (0)
{
int max_tree = 1;
for (int i = 0; i <= max_tree; i++)
{
	printf("%2d: %.6f [%s]\n", i, tree[i].v, tree[i].feat);
	if (strlen(tree[i].feat) > 0) { int tmp = (1+i)*2; if (max_tree < tmp) max_tree = tmp; }
}
}

// Output = new pointer!

		printf("Case #%d: ", c+1);
//	Result Calculation/Display put here
printf("\n");

		FGETS(buf, 4096, in);
		sscanf(buf, "%d", &A);
//printf("%d\n", A);
		for (int i = 0; i < A; i++)
		{
			FGETS(buf, 4096, in);
			// Parse name n fea-1 .. fea-n
			int p = 0;
			int len = 0;
//printf("%s\n", buf);
			sscanf(buf, "%*s%d%n", &featz, &len);
			p += len;
			for (int j = 0; j < featz; j++)
			{
				sscanf(buf+p, "%s%n", feat[j], &len);
				p+=len;
			}

if (0)
{
printf("featz = %d\n", featz);
for (int j = 0; j < featz; j++)
{
	printf(" [%s]", feat[j]);
}
printf("\n");
}

// Cal for me!
double res = 1.0;

int tree_ptr = 0;
while (1)
{
	res *= tree[tree_ptr].v;
	if (strlen(tree[tree_ptr].feat) > 0)
	{
		int has_feat = 0;
		for (int j = 0; j < featz; j++)
		{
			if (strcmp(feat[j], tree[tree_ptr].feat) == 0)
			{
				has_feat = 1;
				break;
			}
		}
		tree_ptr = 2*tree_ptr + (has_feat?1:2);
	}
	else
	{
		break;
	}
}

printf("%.7f\n", res);

		}

	}
	return 0;
}
