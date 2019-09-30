#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <stack>
#include <iomanip>
#include <tuple>
#include <functional>
#include <cfloat>
#include <map>

#define int long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define REMOVE(v,a) (v.erase(remove((v).begin(), (v).end(), (a)), (v).end()))
#define REVERSE(v) (reverse((v).begin(), (v).end()))
#define LOWER_BOUND(v,a) (lower_bound((v).begin(), (v).end(), (a)))
#define UPPER_BOUND(v,a) (upper_bound((v).begin(), (v).end(), (a)))
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define CONTAINS_MAP(m, a) (m).find((a)) != m.end()
using namespace std;

char s[8010];
int tx;
int ty;

int cnt_map[16020];
vector<int> v_list;
vector<int> h_list;

bool func(int target, vector<int>& vec, int init)
{
	memset(cnt_map, -1, sizeof(cnt_map));

	queue<int> q;
	q.push(init);
	cnt_map[init] = 0;

	int cnt = 1;
	for (int n : vec)
	{
		int q_cnt = q.size();
		for (int i = 0; i < q_cnt; i++)
		{
			int a = q.front();
			q.pop();

			for (int j = 0; j < 2; j++)
			{
				int d = a;
				d += (j == 0) ? n : -n;

				if (cnt_map[d] < cnt)
				{
					cnt_map[d] = cnt;
					q.push(d);
				}
			}
		}
		cnt++;
	}

	return cnt_map[target] == vec.size();
}

signed main()
{
	cin >> s;
	cin >> tx >> ty;
	int len = strlen(s);

	int counter = 0;
	int offset = 0;
	for (int i = 0; i <= len; i++)
	{
		if (i == len || s[i] != 'F')
		{
			offset = i;
			counter = i;
			break;
		}
	}

	bool is_v = true;
	while (true)
	{
		int f_cnt = 0;
		if (counter >= len) break;
		while (true)
		{
			counter++;
			if (counter >= len) break;
			if (s[counter] != 'F')
			{
				break;
			}
			f_cnt++;
		}

		if (is_v)
		{
			v_list.push_back(f_cnt);
		}
		else
		{
			h_list.push_back(f_cnt);
		}
		is_v = !is_v;
	}

	bool b1 = func(tx + 8010, h_list, 8010 + offset);
	bool b2 = func(ty + 8010, v_list, 8010);

	if (b1 && b2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}