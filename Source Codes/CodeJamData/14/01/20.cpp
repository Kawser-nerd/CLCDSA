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
	ifstream ifs("a.in");
	ofstream ofs("a.out");
	int t;
	ifs >> t;
	int a[4][4], b[4][4];
	for (int test = 0; test < t; ++test)
	{
		int r1, r2, cnt = 0, num;
		ifs >> r1;
		for (int i = 0;i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				ifs >> a[i][j];

		ifs >> r2;
		for (int i = 0;i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				ifs >> b[i][j];

		--r1; --r2;
		for (int i = 0; i < 4; ++i)
		{
			bool found = false;
			for (int j = 0; j < 4; ++j)
				if (b[r2][j] == a[r1][i])
				{
					++cnt;
					num = b[r2][j];
					break;
				}
		}

		ofs << "Case #" << test+1 << ": ";
		if (cnt == 1) 
		{
			ofs << num; 
		} 
		else if (cnt == 0)
		{
			ofs << "Volunteer cheated!";
		} 
		else if (cnt > 1)
		{
			ofs << "Bad magician!";
		}
		ofs << endl;
	}
	return 0;
}
