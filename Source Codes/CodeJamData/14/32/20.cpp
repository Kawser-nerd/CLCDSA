#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN (128)
#define MAXS (128)
#define MAXC (128)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <PII> VP;

const int moder = 1000000007;

int T;
int N;
char S[MAXN][MAXS];
int len[MAXN];

int V[MAXC];
int rit;

VI edge[MAXC];
int cycle[MAXC];
int inside[MAXC];
int indeg[MAXC];

ll F[MAXN];

int main()
{
	{
		int i;
		F[0] = F[1] = 1;
		for(i = 2; i < MAXN; ++i)
			F[i] = (i * F[i - 1]) % moder;
	}

	scanf("%d", &T);
	for(int TT = 1; TT <= T; ++TT)
	{
		int i, j;
		scanf("%d", &N);
		for(i = 0; i < N; ++i)
		{
			scanf("%s", S[i]);
			len[i] = strlen(S[i]);
		}

		int okay = 1;
		ll sol = 0;

		for(i = 0; i < N && okay; ++i)
		{
			++rit;
			int last = 0;
			set <int> s;
			for(j = 0; j < len[i]; ++j)
			{
				int c = S[i][j];
				s.insert(c);

				if(V[c] != rit)
				{
					V[c] = rit;
					last = c;
				}
				else
				{
					if(last != c)
						okay = 0;
				}
			}

			for(int a : s) // Check for inside word
			{
				if(a != S[i][0] && a != S[i][len[i] - 1])
				{
					if(inside[a] == 1)
						okay = 0;
					inside[a] = 1;
				}
			}
		}

		if(okay)
		{
			for(i = 0; i < N; ++i)
			{
				int a = S[i][0];
				int b = S[i][len[i] - 1];

				if(a != b)
				{
					edge[a].push_back(b);
					++indeg[b];
				}
				else
					++cycle[a];
			}

			for(i = 'a'; i <= 'z'; ++i)
			{
				int od = edge[i].size();
				int id = indeg[i];
				if(od > 1 || id > 1 || (inside[i] && (od + id + cycle[i]) > 0))
					okay = 0;
			}
		}

		int ngroups = 0;

		if(okay)
		{
			++rit;

			for(i = 'a'; i <= 'z'; ++i)
			{
				if(edge[i].size() > 0 && indeg[i] == 0)
				{
					++ngroups;
					int a = i;
					V[a] = rit;
					while(edge[a].size() > 0)
					{
						a = edge[a][0];
						V[a] = rit;
					}
				}

				if(edge[i].size() == 0 && indeg[i] == 0 && cycle[i] > 0)
				{
					V[i] = rit;
					++ngroups;
				}
			}

			for(i = 'a'; i <= 'z'; ++i)
			{
				if(indeg[i] > 0 && V[i] != rit)
					okay = 0;
			}
		}

		if(okay)
		{
			sol = F[ngroups];
			for(i = 'a'; i <= 'z'; ++i)
				sol = (sol * F[cycle[i]]) % moder;
		}

		printf("Case #%d: %I64d\n", TT, sol);

		for(i = 'a'; i <= 'z'; ++i)
		{
			edge[i].clear();
			cycle[i] = 0;
			inside[i] = 0;
			indeg[i] = 0;
		}
	}

	return 0;
}
