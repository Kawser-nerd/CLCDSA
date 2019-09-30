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
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		double c,f,x;
		ifs >> c >> f >> x;
		double curt = 0;
		double curv = 2;
		double bestt = 1e+100;
		while (true)
		{
			double t = curt + (x / curv);
			if (t < bestt) 
			{
				bestt = t;
			}
			else break;

			double dt = c / curv;
			curv += f;
			curt += dt;
		}
		ofs << "Case #" << test+1 << ": " << fixed << setprecision(10) << bestt << endl;
	}
	return 0;
}
