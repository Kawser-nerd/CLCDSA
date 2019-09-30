#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <deque>
#include <limits>
#include <numeric>
#include <boost/math/common_factor_rt.hpp>


#define INF 100000000
#define MOD 1000000007

#define ll long long

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n), h(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> h[i];
	}

	int max = 100;

	for (int posY = 0; posY <= max; posY++)
	{
		for (int posX = 0; posX <= max; posX++)
		{
			int needH = -1;

			for (int i = 0; i < n; i++)
			{
				if (h[i] > 0) {
					int tmp = h[i] + abs(posY - y[i]) + abs(posX - x[i]);
					if (needH == -1) {
						needH = tmp;
					}
					else {
						if (needH != tmp) {
							needH = -2;
							break;
						}
					}
				}
			}
			if (needH == -2)continue;

			for (int i = 0; i < n; i++)
			{
				if (h[i] == 0) {
					int dist = abs(posY - y[i]) + abs(posX - x[i]);
					if (needH > dist) {
						needH = -2;
						break;
					}
				}
			}

			if (needH == -2)continue;

			cout << posX << " " << posY << " " << needH << endl;
			return 0;
		}
	}
	
}