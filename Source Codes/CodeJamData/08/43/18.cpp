#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define pb push_back
#define MP make_pair
#define For(a,b,c) for(typeof(b)a=(b); a<(c); ++a)
#define ALL(a) (a).begin(),(a).end()
#define DBG(a) cout << #a << ": " << a << endl
#define FORE(i, v) for(typeof(v.begin()) i = v.begin(); i != v.end(); ++i)

struct ship
{
	int x, y, z, p;
} s[1000];
int N, maxX, maxY, maxZ;

double go(double x, double y, double z)
{
	double res = 0;
	For (i, 0, N)
	{
		res >?= (abs(x-s[i].x) + abs(y-s[i].y) + abs(z-s[i].z))/ s[i].p;
	}
	return res;
}

double evalz(double x, double y)
{
	double res = HUGE_VAL;
		double zlow = 0, zhigh = maxZ;
		For (i, 0, 50)
		{
			double th = (zhigh-zlow)/3;
			double z1 = th + zlow, z2 = th+th + zlow;
			double a = go(x,y,z1), b = go(x,y,z2);
			res <?= a <? b;
			if (a < b)
				zhigh = z2;
			else
				zlow = z1;
		}
		return res;
}

double evaly(double x)
{
	double res = HUGE_VAL;
		double ylow = 0, yhigh = maxY;
		For (i, 0, 50)
		{
			double th = (yhigh-ylow)/3;
			double y1 = th + ylow, y2 = th+th + ylow;
			double a = evalz(x,y1), b = evalz(x,y2);
			res <?= a <? b;
			if (a < b)
				yhigh = y2;
			else
				ylow = y1;
		}
		return res;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	int T;
	cin >> T;
	For (lol, 1, T+1)
	{
		cin >> N;
		
		maxX = maxY = maxZ = 0;
		For (i, 0, N)
		{
			cin >> s[i].x >> s[i].y >> s[i].z >> s[i].p;
			maxX >?= s[i].x, maxY >?= s[i].y, maxZ >?= s[i].z;
		}
		
		double res = HUGE_VAL;
		
		double xlow = 0, xhigh = maxX;
		For (i, 0, 50)
		{
			double th = (xhigh-xlow)/3;
			double x1 = th + xlow, x2 = th+th + xlow;
			double a = evaly(x1), b = evaly(x2);
			res <?= a <? b;
			if (a < b)
				xhigh = x2;
			else
				xlow = x1;
		}
				
		printf("Case #%d: %.6lf\n", lol, res);
	}
}