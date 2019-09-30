#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

int r, c;
char ma[16][16];
int bi, bj, ei, ej;

int IsGood(char c)
{
	if (c == '.') return 1;
	if (c == '#') return 1;
	if (c == 'O') return 1;
	if (c == 'X') return 1;
	return 0;
}

void Load()
{
	scanf("%d%d", &r, &c);
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			char c = getchar();
			while (! IsGood(c)) c = getchar();
			if (c == 'X')
			{
				ei = i;
				ej = j;
				c = '.';
			}
			else if (c == 'O')
			{
				bi = i;
				bj = j;
				c = '.';
			}
			ma[i][j] = c;
		}
	}
}

class Vertex
{
public:
	int ci, cj, pi, pj;
};

bool operator<(const Vertex &a, const Vertex &b)
{
	if (a.ci < b.ci) return true;
	if (a.ci > b.ci) return false;
	if (a.cj < b.cj) return true;
	if (a.cj > b.cj) return false;
	if (a.pi < b.pi) return true;
	if (a.pi > b.pi) return false;
	if (a.pj < b.pj) return true;
	if (a.pj > b.pj) return false;
	return false;
}

map<Vertex, int> dst;
list<Vertex> q;

void Solve()
{
	dst.clear();
	Vertex bver;
	bver.ci = bi;
	bver.cj = bj;
	bver.pi = -1;
	bver.pj = -1;
	dst[bver] = 0;
	q.push_back(bver);
	while (q.size() > 0)
	{
		Vertex a = *q.begin();
		q.erase(q.begin());
		int k;
		for (k = 0; k < 4; k++)
		{
			int ni = a.ci + di[k];
			int nj = a.cj + dj[k];                                
			if ((ni < 0) || (ni >= r) || (nj < 0) || (nj >= c) || (ma[ni][nj] == '#')) 
			{
				Vertex b = a;
				b.ci = a.pi;
				b.cj = a.pj;
				if ((dst.find(b) == dst.end()) || (dst[b] > dst[a] + 1))
				{
					dst[b] = dst[a] + 1;
					q.push_back(b);
				}
			}
			else
			{
				Vertex b = a;
				b.ci = ni;
				b.cj = nj;
				if ((dst.find(b) == dst.end()) || (dst[b] > dst[a] + 1))
				{
					dst[b] = dst[a] + 1;
					q.push_back(b);
				}
			}
		}
		for (k = 0; k < 4; k++)
		{
			int ni = a.ci + di[k];
			int nj = a.cj + dj[k];
			while ((ni >= 0) && (ni < r) && (nj >= 0) && (nj < c) && (ma[ni][nj] == '.'))
			{
				ni += di[k];
				nj += dj[k];
			}
			ni -= di[k];
			nj -= dj[k];
			Vertex b = a;
			b.pi = ni;
			b.pj = nj;
			if ((dst.find(b) == dst.end()) || (dst[b] > dst[a]))
			{
				dst[b] = dst[a];
				q.push_front(b);
			}
		}
	}
	int md = 2000000000;
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			Vertex a;
			a.ci = ei;
			a.cj = ej;
			a.pi = i;
			a.pj = j;
			if (dst.find(a) != dst.end())
			{
				if (dst[a] < md) md = dst[a];
			}
		}
	}
	if (md == 2000000000) cout << "THE CAKE IS A LIE";
	else cout << md;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}