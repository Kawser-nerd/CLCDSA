#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");

#define cin fin
#define cout fout

#define LIMIT 390001

int ans;

struct Tp {
	int x, y;
} p[1100];
int n;

struct Tstat {
	int num[5];
};

vector <Tstat> que[2][LIMIT];
int used[3];

int ten[6];

void add(int id, Tstat & a)
{
	unsigned long key = 0;
	for (int i = 0; i < 5; i++)
		key = ((key << 16) + a.num[i]) % LIMIT;
	
	int templen = que[id][key].size();
	for (int i = 0; i < templen; i++)
	{
		bool flag = true;
		for (int j = 0; j < 5; j++)
			if (a.num[j] != que[id][key][i].num[j])
			{
				flag = false;
				break;
			}
		if (flag == true) return;
	}

	que[id][key].push_back(a);
}

bool solve(int maxc)
{
	int last[40];
	memset(last, 0xff, sizeof(last));
	
	Tstat newS;
	memset(&newS, 0, sizeof(newS));
	
	for (int i = 0; i < LIMIT; i++)
		que[0][i].clear();
	que[0][0].push_back(newS);

	int now = 0;
	int usec, lastc;

	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < LIMIT; j++)
			que[1-now][j].clear();

		bool flag = false;
		int y0 = p[i].y-1;

		for (int j = 0; j < LIMIT; j++)
			for (int k = 0; k < que[now][j].size(); k++)
			{
				for (int h = 0; h < 5; h++)
					newS.num[h] = que[now][j][k].num[h];

				memset(used, 0, sizeof(used));

				for (int d = -1; d <= 1; d++)
				{
					int y1 = y0 + d;
					if (y1 >= 0 && y1 < 30 && last[y1] != -1)
					{
						usec = (que[now][j][k].num[y1/6] / ten[y1%6]) % 10;
						used[usec] = 1;
					}
				}

				for (int d = 0; d < maxc; d++)
					if (used[d] == 0)
					{
						lastc = (newS.num[ y0/6] / ten[y0%6]) % 10;
						newS.num[y0/6] = newS.num[y0/6] - lastc * ten[y0%6] + d * ten[y0%6];						

						add(1-now, newS);
						flag = true;

						newS.num[y0/6] = newS.num[y0/6] + lastc * ten[y0%6] - d * ten[y0%6];
					}
			}
		
		if (flag == false) return false;

		last[y0] = p[i].x;
		now = 1-now;
	}

	return true;
}

int main()
{
	int cases;

	ten[0] = 1;
	for (int i = 1; i < 6; i++)
		ten[i] = ten[i-1] * 10;

	cin >> cases;

	for (int i = 1; i <= cases; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> p[j].x >> p[j].y;

		for (int j = 0; j < n; j++)
			for (int k = j+1; k < n; k++)
				if (p[j].x > p[k].x)
				{
					swap(p[j], p[k]);
				}

		ans = 4;
		for (int j = 1; j <= 3; j++)
		{
			if (solve(j) == true)
			{
				ans = j;
				break;
			}
		}

		cout << "Case #" << i << ": " << ans << endl;
	}

	return 0;
}