#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n, m, cnt;
		ifs >> n >> m >> cnt;
		vector<string> v(n, string(m, '.'));
		int cur = 0;
		if (cnt == n*m-1) 
		{
			v = vector<string>(n, string(m, '*'));
			v[n-1][m-1] = 'c';
			cur = cnt;
		}
		else 
		{
			for (int i = 0; i+2 < n || (n == 1 || m == 1) && i < n; ++i)
				for (int j = 0; j+2 < m || (n == 1 || m == 1) && j < m; ++j)
				{
					if (n-i > 2 || m - j > 2)
						if (cur < cnt) 
						{
							v[i][j] = '*';
							++cur;
						}
				}

			v[n-1][m-1] = 'c';
			if (cur < cnt && n > 1 && m > 1) 
			{
				int d = cnt - cur;
				int k = 2;
				if (d % 2 == 1 && n > 2 && m > 2) 
				{
					v[n-3][m-3] = '.';
					--cur;
					k = 3;
					++d;
				}
				for (int i = 0; i <= n-k && d % 2 == 0; ++i)
				{
					int d1 = d - i*2;
					if (d1 >= 0 && d1 <= (m-k)*2)
					{
						for (int j = 0; j < i; ++j)
						{
							v[j][m-1] = '*';
							v[j][m-2] = '*';
						}
						for (int j = 0; j < d1/2; ++j)
						{
							v[n-1][j] = '*';
							v[n-2][j] = '*';
						}
						cur = cnt;
						break;
					}
				}
			}
		}

		ofs << "Case #" << test+1 << ":\n";
		if (cur < cnt) ofs << "Impossible\n";
		else 
		{
			for (int i = 0; i < n; ++i)
			{
				ofs << v[i] << endl;
			}
		}
	}
	return 0;
}
