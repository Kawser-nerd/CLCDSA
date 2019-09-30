#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <map>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 90001

using namespace std;

ll m, a, r, c, h;

ll max(ll a, ll b)
{
	return a > b ? a : b;
}

int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int N; cin >> N;
	while (N--)
	{
		string temp; cin >> temp;
		char t = temp[0];
		switch (t)
		{
		case 'M':
			m += 1;
			break;
		case 'A':
			a += 1;
			break;
		case 'R':
			r += 1;
			break;
		case 'C':
			c += 1;
			break;
		case 'H':
			h += 1;
		}
	}
	if (m + a + r + c + h < 3)
	{
		cout << 0;
		return 0;
	}
	ll ret = 0;
	ll arr[5] = { m, a, r, c, h };
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				ret += arr[i] * arr[j] * arr[k];
			}
		}
	}

	cout << ret << endl;
	return 0;
}