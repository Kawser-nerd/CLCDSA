#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

const long double MAXY = 1000000;
const long double eps = 1e-12;

long long w, h;
long long bx, by, dx1, dy1, dx2, dy2;

void Load()
{
	cin >> w >> h;
	cin >> dx1 >> dy1 >> dx2 >> dy2 >> bx >> by;
}

class Otr
{
public:
	long double x1, y1, x2, y2;
};


vector<Otr> o;

void Convert(long double xx, long double yy, long double &rx, long double &ry)
{
	long double c1 = xx - bx;
	long double c2 = yy - by;
	long double d = dx1 * dy2 - dy1 * dx2;
	rx = c1 * dy2 - dx2 * c2;
	ry = dx1 * c2 - c1 * dy1;
	rx /= d;
	ry /= d;
	//cerr << "Converting " << xx << " " << yy << " got " << rx << " " << ry << "\n";
	//cerr << "Resulting: " << bx + rx * dx1 + ry * dx2 << " " << by + rx * dy1 + ry * dy2 << "\n";
}

void TMXMX(Otr o, long double y, long double &minx, long double &maxx)
{
	if (fabs(o.y1 - o.y2) < eps)
	{
		if (fabs(o.y1 - y) < eps)
		{
			minx = min(minx, o.x1);
			minx = min(minx, o.x2);
			maxx = max(maxx, o.x1);
			maxx = max(maxx, o.x2);
		}
	}
	else
	{
		long double t = (y - o.y1) / (o.y2 - o.y1);
		if ((t > -eps) && (t < 1 + eps))
		{
			long double x = o.x1 + t * (o.x2 - o.x1);
			minx = min(x, minx);
			maxx = max(x, maxx);
		}
	}
}

long long SolveDull()
{
	vector<pair<int, int> > q;
		set<pair<int, int> > was;
		q.clear();
		was.clear();
		q.push_back(make_pair(bx, by));
		was.insert(q[0]);
		int hd = 0;
		while (hd < q.size())
		{
			int nx, ny;
			nx = q[hd].first + dx1;
			ny = q[hd].second + dy1;
			if ((nx >= 0) && (nx < w) && (ny >= 0) && (ny < h))
			{
				if (was.find(make_pair(nx, ny)) == was.end())
				{
					q.push_back(make_pair(nx, ny));
					was.insert(make_pair(nx, ny));
				}
			} 
			nx = q[hd].first + dx2;
			ny = q[hd].second + dy2;
			if ((nx >= 0) && (nx < w) && (ny >= 0) && (ny < h))
			{
				if (was.find(make_pair(nx, ny)) == was.end())
				{
					q.push_back(make_pair(nx, ny));
					was.insert(make_pair(nx, ny));
				}
			}
			hd++;
		}
	return was.size();
}

void Solve()
{
	long long ans = 0;
	if (dx1 * dy2 - dy1 * dx2 == 0)
	{
		cerr << "botva\n";
		ans = SolveDull();
	}
	else
	{
		int i;
		o.clear();
		Otr a;
		Convert(0, 0, a.x1, a.y1);
		Convert(w - 1, 0, a.x2, a.y2);
		o.push_back(a);
		Convert(w - 1, h - 1, a.x1, a.y1);
		Convert(w - 1, 0, a.x2, a.y2);
		o.push_back(a);
		Convert(w - 1, h - 1, a.x1, a.y1);
		Convert(0, h - 1, a.x2, a.y2);
		o.push_back(a);
		Convert(0, h - 1, a.x1, a.y1);
		Convert(0, 0, a.x2, a.y2);
		o.push_back(a);
		/*if (dx1 * dy2 - dy1 * dx2 < 0)
		{
			for (i = 0; i < o.size(); i++)
			{
				o[i].x1 = -o[i].x1;
				//o[i].y1 = -o[i].y1;
				o[i].x2 = -o[i].x2;
				//o[i].y2 = -o[i].y2;
			}
		}*/
		// brute y
		long double y;
		long double miny, maxy;
		maxy = miny = o[0].y1;
		for (i = 0; i < o.size(); i++)
		{
			miny = min(miny, o[i].y1);
			maxy = max(maxy, o[i].y1);
			miny = min(miny, o[i].y2);
			maxy = max(maxy, o[i].y2);
		}
		long long minyl = ((long long)(miny + eps));
		long long maxyl = ((long long)(maxy + eps));
		long long pminx, pmaxx;
		pminx = pmaxx = 0;
		for (y = minyl - 10; y < maxyl + 10; y++)
		{
			if (y < -eps) continue;
			long double minx, maxx;
			minx = 1e100;
			maxx = -1e100;
			for (i = 0; i < o.size(); i++)
			{
				TMXMX(o[i], y, minx, maxx);
			}
			if (minx < -eps) minx = 0;
			if (minx < maxx + eps)
			{
				long long minxl = ((long long)(minx - eps));
				while (minxl < minx - eps) minxl++;
				long long maxxl = ((long long)(maxx + eps));
				while (maxxl > maxx + eps) maxxl--;
				minxl = max(minxl, pminx);
				if ((minxl <= maxxl) && (minxl <= pmaxx))
				{
					ans += (maxxl - minxl + 1);
					pminx = minxl;
					pmaxx = maxxl;
				}
				else break;
			}
		}
		/*if (ans != SolveDull())
		{
			ofstream out("test.txt");
			out << w << " " << h << "\n";
			out << dx1 << " " << dy1 << "\n" << dx2 << " " << dy2 << "\n" << bx << " " << by;
			out.close();
			cerr << "big botva";
		}*/
	}
	cout << ans;
	//cerr << ans << " " << SolveDull() << "\n";
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		cerr << it << "\n";
		printf("Case #%d: ", it + 1);
		Load();
		Solve();
		printf("\n");
	}
	return 0;
}