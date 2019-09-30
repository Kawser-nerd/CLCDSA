#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int t = 1; t <= N; ++t)
	{
		int m, x;
		double p;
		cin >> m >> p >> x;
		map<double, double> prob;
		prob[1000000] = 1;
		prob[500000] = p;
		prob[0] = 0;
		for(int i = 0; i < m - 1; ++i)
		{
			map<double, double> next;
			for(map<double, double>::iterator it = prob.begin(); it != prob.end(); ++it)
			{
				for(map<double, double>::iterator itt = it; itt != prob.end(); ++itt)
				{
					double d = next[(it->first + itt->first) / 2];
					next[(it->first + itt->first) / 2] = max(d, p * itt->second + (1 - p) * it->second);
				}
			}
			prob = next;
		}
		double res = 0;
		for(map<double, double>::iterator it = prob.begin(); it != prob.end(); ++it)
		{
			map<double, double>::iterator next = it;
			++next;
			if(it->first <= x && (next == prob.end() || x < next->first)) res = it->second;
		}
		printf("Case #%d: ", t);
		printf("%.10f\n", res);
	}
	return 0;
}
