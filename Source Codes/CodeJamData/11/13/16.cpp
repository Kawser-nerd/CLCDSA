#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>;
using namespace std;

struct card
{
	int c, s, t;
	bool flag;
};

int T;
int N, M;
card a[100];
card b[100];
card c[100];

int checkMax(int c0, int c1, int c2)
{
	int base = N, turn = 1, score = 0;
	for (int i=0; i<N; i++) c[i] = a[i];
	for (int j=0; j<M; j++) c[j+N] = b[j];
	for (int j=0; j<N+M; j++) c[j].flag = true;

	while (turn > 0)
	{
		bool flag = true;
		if (base > N+M)
			base = N+M;
		for (int i=0; i<base; i++)
			if (c[i].flag && c[i].t > 0)
			{
				base+=c[i].c;
				turn+=c[i].t;
				score+=c[i].s;
				if (c[i].c==0) c0--;
				else if (c[i].c==1) c1--;
				else if (c[i].c==2) c2--;
				flag = false;
				c[i].flag = false;
				break;
			}
		if (c2 > 0 && flag)
		{
			int cScore = -1, cKey = 0;
			for (int i=0; i<base; i++)
				if (c[i].flag && c[i].c == 2 && c[i].s>cScore)
				{
					cScore = c[i].s;
					cKey = i;
				}
			if (cScore >= 0)
			{
				base+=c[cKey].c;
				turn+=c[cKey].t;
				score+=c[cKey].s;
				c2--;
				flag = false;
				c[cKey].flag = false;
			}
		}
		if (c1 > 0 && flag)
		{
			int cScore = -1, cKey = 0;
			for (int i=0; i<base; i++)
				if (c[i].flag && c[i].c == 1 && c[i].s>cScore)
				{
					cScore = c[i].s;
					cKey = i;
				}
			if (cScore >= 0)
			{
				base+=c[cKey].c;
				turn+=c[cKey].t;
				score+=c[cKey].s;
				c1--;
				flag = false;
				c[cKey].flag = false;
			}
		}
		if (c0 > 0 && flag)
		{
			int cScore = -1, cKey = 0;
			for (int i=0; i<base; i++)
				if (c[i].flag && c[i].c == 0 && c[i].s>cScore)
				{
					cScore = c[i].s;
					cKey = i;
				}
			if (cScore >= 0)
			{
				base+=c[cKey].c;
				turn+=c[cKey].t;
				score+=c[cKey].s;
				c0--;
				flag = false;
				c[cKey].flag = false;
			}
		}
		if (c0 <=0 && c1<=0 && c2<=0)
			return score;
		turn--;
	}
	return score;
}

bool checkPossible(int c0, int c1, int c2)
{
	int base = N, turn = 1;
	for (int i=0; i<N; i++) c[i] = a[i];
	for (int j=0; j<M; j++) c[j+N] = b[j];
	for (int j=0; j<N+M; j++) c[j].flag = true;

	while (turn > 0)
	{
		bool flag = true;
		if (base > N+M)
			base = N+M;
		for (int i=0; i<base; i++)
			if (c[i].flag && c[i].t > 0)
			{
				base+=c[i].c;
				turn+=c[i].t;
				if (c[i].c==0) c0--;
				else if (c[i].c==1) c1--;
				else if (c[i].c==2) c2--;
				flag = false;
				c[i].flag = false;
				break;
			}
		if (c2 > 0 && flag)
		{
			for (int i=0; i<base; i++)
			if (c[i].flag && c[i].c == 2)
			{
				base+=c[i].c;
				turn+=c[i].t;
				c2--;
				flag = false;
				c[i].flag = false;
				break;
			}
		}
		if (c1 > 0 && flag)
		{
			for (int i=0; i<base; i++)
			if (c[i].flag && c[i].c == 1)
			{
				base+=c[i].c;
				turn+=c[i].t;
				c1--;
				flag = false;
				c[i].flag = false;
				break;
			}
		}
		if (c0 > 0 && flag)
		{
			for (int i=0; i<base; i++)
			if (c[i].flag && c[i].c == 0)
			{
				base+=c[i].c;
				turn+=c[i].t;
				c0--;
				flag = false;
				c[i].flag = false;
				break;
			}
		}
		if (c0 <=0 && c1<=0 && c2<=0)
			return true;
		turn--;
	}
	return false;
}

int solve()
{
	int baseC = 0, baseS = 0, baseT = 1;
	if (N==0)
		return 0;
	int max0 = 0, max1 = 0, max2 = 0;
	for (int i=0; i<N; i++)
		if (a[i].c==0) max0++;
		else if (a[i].c==1) max1++;
		else if (a[i].c==2) max2++;
	for (int i=0; i<M; i++)
		if (b[i].c==0) max0++;
		else if (b[i].c==1) max1++;
		else if (b[i].c==0) max2++;
	
	int ret = 0;
	for (int c0 = 0; c0 <=max0; c0++)
		for (int c1 = 0; c1 <=max1; c1++)
			for (int c2 = 0; c2 <= max2; c2++)
				if (checkPossible(c0, c1, c2))
				{
					int max = checkMax(c0, c1, c2);
					if (max > ret) ret = max;
				}
	return ret;
}

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for (int i=1; i<=T; i++)
	{
		memset(a, 0, sizeof(a));
		cin >> N;
		int c, s, t;
		for (int j=0; j<N; j++)
		{
			cin >> c >> s >> t;
			a[j].c = c;
			a[j].s = s;
			a[j].t = t;
			a[j].flag = true;
		}
		cin >> M;
		for (int j=0; j<M; j++)
		{
			cin >> c >> s >> t;
			b[j].c = c;
			b[j].s = s;
			b[j].t = t;
			b[j].flag = true;
		}
		cout << "Case #" << i << ": " << solve() << endl;
	}
}