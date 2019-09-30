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
	ifstream ifs("d.in");
	ofstream ofs("d.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		double a[1000], b[1000];
		for (int i = 0; i < n; ++i)
		{
			ifs >> a[i];
		}
		for (int i = 0; i < n; ++i)
		{
			ifs >> b[i];
		}
		sort(a, a+n);
		sort(b, b+n);

		int was[1000] = {0};
		int resa = 0;
		for (int i = 0; i < n; ++i)
		{
			bool found= false;
			for (int j = 0; j < n; ++j)
				if (was[j] == 0 && b[j] > a[i])
				{
					was[j] = 1;
					found = true;
					break;
				}
			if (!found) ++resa;
		}

		int resb = 0;
		int curj = 0; 
		for (int i =0; i < n; ++i)
		{
			if (a[i] > b[curj]) 
			{
				++resb;
				++curj;
			}
		}
		ofs << "Case #" << test+1 << ": " << resb << ' ' << resa << endl;
	}
	return 0;
}
