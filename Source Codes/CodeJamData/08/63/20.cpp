#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>

using namespace std;

#define all(x) (x).begin(),(x).end()

int m;
double p;
int x;

double table[6][1000001];

inline double go(int a, int b)
{
	if (b >= 1000000) return 1.0;
	if (b <= 0) return 0.0;
	if (a == 0) return 0.0;

	return table[a][b];
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn)
	{
		printf("Case #%d: ", cn);
		cin >> m >> p >> x;

		memset(table, 0, sizeof(table));

		vector <int> gugan;
		gugan.push_back(0);
		gugan.push_back(1000000);

		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j <= 1000000; ++j)
			{
				// allin or 잃었는데 gugan에 맞게
				double ret = 0.0;
				ret >?= p * go(i - 1, j + j) + (1 - p) * go(i - 1, 0);
				for (int k = 0; k < gugan.size(); ++k)
				{
					int money = j - gugan[k];
					if (money < 0) continue;
					ret >?= p * go(i - 1, j + money) + (1 - p) * go(i - 1, j - money);
				}
				table[i][j] = ret;
			}
			int t = gugan.size();
			for (int i = 0; i < t - 1; ++i)
			{
				gugan.push_back((gugan[i] + gugan[i + 1]) / 2);
			}
			sort(all(gugan));
		}
		printf("%.6lf\n", go(m, x));
	}
}

