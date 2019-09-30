#include <stdio.h>
#include <set>

using namespace std;

int n, m;
struct abracadabra
{
	int c, s, t;
	bool used;
};

abracadabra hand[100];
int score, best;

set<pair<long long, int> > S;

bool seen ()
{
	long long a = 0;
	int b = 0;

	for (int i = 0; i < m; i ++)
		if (i < 60)
			a = a * 2 + hand[i].used;
		else
			b = b * 2 + hand[i].used;

	if (S.find(make_pair(a, b)) != S.end())
		return true;
	S.insert(make_pair(a, b));
	return false;
}

void dfs (int turn, int usefulTurns)
{
	if (score > best) best = score;

	if (turn == 0)
		return;

	if (seen())
		return;

	for (int i = 0; i < n && i < m; i ++)
		if (!hand[i].used)
		{
			bool ok = true;
			for (int j = 0; j < n && j < m; j ++)
				if (j != i 
					&& !hand[j].used && hand[j].s >= hand[i].s 
					&& min(usefulTurns-turn, hand[j].t) >= min(usefulTurns-turn, hand[i].t) 
					&& min(m - n, hand[j].c) >= min(m - n, hand[i].c)
					&& (j < i
					|| hand[j].s > hand[i].s 
					|| min(usefulTurns-turn, hand[j].t) > min(usefulTurns-turn, hand[i].t) 
					|| min(m - n, hand[j].c) > min(m - n, hand[i].c)
					)
					)
					ok = false;

			if (ok)
			{
				// play this?
				hand[i].used = true;

				score += hand[i].s;
				turn += hand[i].t;
				n += hand[i].c;

				dfs (turn - 1, usefulTurns - 1);

				hand[i].used = false;

				score -= hand[i].s;
				turn -= hand[i].t;
				n -= hand[i].c;
			}
		}
}

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf ("%d%d%d", &hand[i].c, &hand[i].s, &hand[i].t);
		scanf ("%d", &m);
		for (int i = n; i < n + m; i ++)
			scanf ("%d%d%d", &hand[i].c, &hand[i].s, &hand[i].t);
		m += n;

		for (int i = 0; i < m; i ++)
			hand[i].used = false;
		
		score = best = 0;
		S.clear();
		dfs (1, m);

		printf ("Case #%d: %d\n", ++ ct, best);
	}

	return 0;
}

/*
30
0 0 1
1 3 0
0 5 0
0 9 2
0 0 0
0 7 1
1 1 0
0 6 0
1 8 0
1 7 1
1 9 0
0 2 0
0 7 0
0 5 0
0 8 1
1 2 0
1 7 0
1 8 0
0 1 2
1 0 0
0 4 1
0 6 1
1 0 1
1 9 1
0 1 0
0 1 2
0 7 0
0 2 1
0 0 0
1 8 0
14
1 1 0
1 2 0
1 1 0
0 8 0
1 1 2
0 4 0
0 0 1
0 9 0
1 3 0
1 2 0
1 7 0
0 0 1
1 5 0
1 2 1
*/