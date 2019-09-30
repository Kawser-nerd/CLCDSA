#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;



const long long mod = 1000002013;

int N;

long long getPrice(long long a)
{
	long long ans = a * (N + N - a + 1) / 2;
	return ans % mod;
}


vector <pair<int, int> > q;
priority_queue <pair <int, int> > qu;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++)
	{
		q.clear();
		int n, m;
		scanf("%d%d", &n, &m);
		N = n;
		long long mustBe = 0;

		for (int i = 0; i < m; i++)
		{
			int a, b, p;
			scanf("%d%d%d", &a, &b, &p);
			mustBe += getPrice(b - a) * p;
			mustBe %= mod;

			q.push_back(make_pair(a, -p) );
			q.push_back(make_pair(b, p) );
		}

		sort(q.begin(), q.end() );


		long long curCnt = 0, realAns = 0;

		for (int i = 0; i < q.size(); i++)
		{
			int curIn = -q[i].second;
			int curPos = q[i].first;

			if (curIn > 0)
			{
				qu.push(make_pair(curPos, curIn) );
			}
			else
			{
				curIn = -curIn;
				while (curIn > 0)
				{
					pair<int, int> quT = qu.top();
					qu.pop();
					int d = min(curIn, quT.second);
					
					quT.second -= d;
					curIn -= d;



					if (quT.second > 0)
						qu.push(quT);

					realAns += getPrice(curPos - quT.first) * d;
					realAns %= mod;
				}
			}

		}
		long long ans = mustBe - realAns;
		ans += mod;
		ans %= mod;

		printf("Case #%d: %d\n", t + 1, ans);
	}



	return 0;
}