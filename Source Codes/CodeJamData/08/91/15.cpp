#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n;
vector<pair<int, pair<int, int> > > data;

void Load()
{
	data.clear();
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		data.push_back(make_pair(a, make_pair(b, c)));
	}
}

int ubound;
vector<pair<int, int> > rd;
const int TSIZE = 16384;
int sum[2 * TSIZE + 10];

void AddTree(int pos)
{
	pos += TSIZE;
	while (pos >= 1)
	{
		sum[pos]++;
		pos >>= 1;
	}
}

int FindSum(int ub)
{
	int l = TSIZE;
	int r = ub + TSIZE;
	int res = 0;
	while (l <= r)
	{
		if ((l & 1) == 1)
		{
			res += sum[l];
			l++;
		}
		if ((r & 1) == 0)
		{
			res += sum[r];
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return res;
}

int GetAns()
{
	memset(sum, 0, sizeof(sum));
	sort(rd.begin(), rd.end());
	int i;
	int num = 0;
	for (i = 0; i < rd.size(); i++)
	{
		AddTree(rd[i].second);
		int cc = FindSum(ubound - rd[i].first);
		num = max(num, cc);
	}
	return num;
}

void Solve()
{
	sort(data.begin(), data.end());
	int i;
	int oans = 0;
	rd.clear();
	for (i = 0; i < data.size(); i++)
	{
		rd.push_back(data[i].second);
		ubound = 10000 - data[i].first;
		int cans = GetAns();
		oans = max(oans, cans);
	}
	printf("%d", oans);
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