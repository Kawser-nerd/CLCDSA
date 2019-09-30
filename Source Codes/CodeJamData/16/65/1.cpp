#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

ifstream fin ("E.in");
ofstream fout ("E.out");

int N;
double A, B, C;

double c;
double r1, r2, ang;

double sq (double x)
{
	return x * x;
}

double hype (double x, double y) // hype
{
	return sqrt (x * x + y * y);
}

double score (double x, double r)
{
	x = sqrt (sq (x) - sq (r));
	//cout << x << " " << r << "\n";
	return x + atan (x / r) / r;
}

double area (double a, double b, double c)
{
	double s = (a + b + c) / 2.;
	return sqrt (s * (s - a) * (s - b) * (s - c));
}

int main()
{
	fout << fixed << setprecision(5);
	int ntest; fin >> ntest;
	for (int test = 0; test < ntest; test++)
	{
	fin >> N >> A >> C >> B;
	r1 = hype (10, B - A);
	r2 = hype (10, C - B);
	c = hype (20, C - A);
	
	//cout << area (r1, r2, c) << " " << c << "\n";
	double h = area (r1, r2, c) * 2 / c;
	
	ang = acos ((sq(r1) + sq(r2) - sq(c)) / (2. * r1 * r2));
	
	double ans = 1e9;
	for (double r = h; r < r1 && r < r2; r += 0.001)
	{
		double tot = score (r1, r) + score (r2, r);
		double nang = ang - acos (r / r1) - acos (r / r2);
		//cout << nang << " " << r << "\n";
		tot += nang * r + nang / r;
		
		ans = min (ans, tot);
	}
	
	fout << "Case #" << test + 1 << ": ";
	fout << ans - 0.02 << "\n";
	
	}
	
	return 0;
}
