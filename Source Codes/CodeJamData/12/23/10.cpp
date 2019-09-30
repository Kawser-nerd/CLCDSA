#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

const int nmax = 500;
const int N = 5000000;
const int bits = 50;

vector<short> randomVector(int n)
{
	vector<short> ret(bits);
	bool *u = new bool[nmax];
	for(int i = 0; i < nmax; i++)
		u[i] = 0;
	for(int i = 0; i < bits; i++)
	{
		while(true)
		{
			int b = rand() % nmax;
			if (u[b]) continue;
			ret[i] = b;
			u[b] = true;
			break;
		}
	}
	delete []u;
	return ret;
}

void genTest()
{
	freopen("input.txt", "w", stdout);
	cout << 1 << endl;
	cout << nmax << endl;
	for(int i = 0; i < nmax; i++)
		cout << 1LL * rand() * rand() * rand() % 1000000000000LL + 1 << " ";
}

int main()
{
	//genTest();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, n, m, i, j, k, h, t;
	long long s[nmax];

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> s[i];
		printf("Case #%d:\n", t);

		vector<pair<long long, vector<short> > > sums(N);
		bool found = false;
		for(int it = 0; it < 20; it++)
		{
			printf("%d\n", it);
			for(i = 0; i < N; i++)
			{
				vector<short> tmp = randomVector(n);
				long long S = 0;
				for(j = 0; j < tmp.size(); j++)
					S += s[tmp[j]];
				sums[i] = make_pair(S, tmp);
			}

			sort(sums.begin(), sums.end());
			for(i = 1; i < N; i++)
				if (sums[i].first == sums[i - 1].first && sums[i].second != sums[i - 1].second)
				{
					found = true;
					for(j = 0; j < sums[i].second.size(); j++)
						printf("%lld ", s[sums[i].second[j]]);
					puts("");
					for(j = 0; j < sums[i - 1].second.size(); j++)
						printf("%lld ", s[sums[i - 1].second[j]]);
					puts("");
					break;
				}
			if (i < N) break;
		}
		if (!found)
			puts("Impossible");
	}

	return 0;
}