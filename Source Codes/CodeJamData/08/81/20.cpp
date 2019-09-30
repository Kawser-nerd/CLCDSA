#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>
using namespace std;
namespace wx
{

long long x1, y1, x2, y2, x3, y3;
long long nx1, ny1, nx2, ny2, nx3, ny3;


class Point
{
	public:
	long long x, y;
	long long len2()
	{
		return x*x + y*y;
	}
};


Point operator + (Point a, Point b)
{
	Point c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Point operator - (Point a, Point b)
{
	Point c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}


long long operator * (Point a, Point b)
{
	return a.x * b.x + a.y * b.y;
}


long long operator ^ (Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}

  
Point vs[3];
Point nvs[3];



void Load()
{
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
	cin >> nx1 >> ny1 >> nx2 >> ny2 >> nx3 >> ny3;
	vs[0].x = x2 - x1;
	vs[0].y = y2 - y1;
	vs[1].x = x3 - x2;
	vs[1].y = y3 - y2;
	vs[2].x = x1 - x3;
	vs[2].y = y1 - y3;
	nvs[0].x = nx2 - nx1;
	nvs[0].y = ny2 - ny1;
	nvs[1].x = nx3 - nx2;
	nvs[1].y = ny3 - ny2;
	nvs[2].x = nx1 - nx3;
	nvs[2].y = ny1 - ny3;
}





void Solve()
{
	int i, j, f;

	for (i = 0; i < 3; i++)
	{
		f = 1;
		for (j = 0; j < 2; j++)
		{
			if (vs[j].len2()*nvs[(j+i+1)%3].len2() != vs[j+1].len2() * nvs[(j+i)%3].len2()) f = 0;
	   	}
	   	if (f) break;
	}

	long double cosa = (vs[0]*nvs[i]) / sqrt(vs[0].len2()*nvs[i].len2());
	long double sina = (vs[0]^nvs[i]) / sqrt(vs[0].len2()*nvs[i].len2());
	long double k = sqrt((nvs[i].len2() + 0.0) / vs[0].len2());
	long double dx = (cosa * x1 - sina * y1) * k ;
	long double dy = (sina * x1 + cosa * y1) * k ;
	long double xx = 0, yy = 0, xxx, yyy; 
	switch (i){
	case 0:
		xx = nx1; yy = ny1;	
	break;
	case 1:
		xx = nx2; yy = ny2;
	break;
	case 2:
		xx = nx3; yy = ny3;
	break;
	}
	dx = xx - dx;
	dy = yy - dy;


	sina *= k;
	cosa *= k;

	cosa -= 1;


	//	0 = cosa * xx - sina * yy + dx;
	//	0 = sina * xx + cosa * yy + dy;

	xxx = cosa*cosa+sina*sina;
	xx = -dx*cosa-dy*sina;
	yy = -(cosa*dy-sina*dx);
	xx /= xxx;
	yy /= xxx;


	cout.precision(6);
	cout.setf(ios::fixed|ios::showpoint);
	cout << xx << ' ' << yy << "\n";
}

}

int main()
{
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);
	int tt = 0;
    int nt;
    cin >> nt;
    for (tt= 1; tt <= nt; tt++)
    {
		wx::Load();
		cout << "Case #" << tt << ": ";
    	wx::Solve();
    }
	return 0;
}

