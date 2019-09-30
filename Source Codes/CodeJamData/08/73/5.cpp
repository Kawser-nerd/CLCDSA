#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int n;
double a[10000*30+100];
ll z[10000*30+100];
int q, m;
double p[40][4];

double ans;

set<ll> used;
ll full[30];
ll unit[30];

bool isused(ll z)
{
	if (used.find(z) != used.end())
		return true;
	else
	{
		used.insert(z);
		return false;
	}
}

void up(int m)
{
	double baka = a[m];
	ll bakz = z[m];
	int x = m/2;
	while (m > 1)
	{
		if (baka <= a[x]) break;
		a[m] = a[x];
		z[m] = z[x];
		m /= 2;
		x /= 2;
	}
	a[m] = baka;
	z[m] = bakz;
}

void down(int m)
{
	double baka = a[m];
	ll bakz = z[m];
	int x = m*2;
	while (x <= n)
	{
		if (x < n && a[x+1] > a[x]) x++;
		if (baka >= a[x]) break;
		a[m] = a[x];
		z[m] = z[x];
		m = x;
		x = m*2;
	}
	a[m] = baka;
	z[m] = bakz;
}

void add(double v, ll _z)
{
	n++;
	a[n] = v;
	z[n] = _z;
	up(n);
}

void del()
{
	a[1] = a[n];
	z[1] = z[n];
	n--;
	down(1);
}

int main()
{
	FI(i,0,30)
	{
		unit[i] = ((ll)1) << (i*2);
		full[i] = unit[i]*3;
	}
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
		//istringstream strin();
		fin >> m >> q;
		FI(i,0,q)
		{
			FI(j,0,4) fin >> p[i][j];
			FI(j,0,4) FI(k,j+1,4) if (p[i][j] < p[i][k]) swap(p[i][j], p[i][k]);
			for (int j = 3; j >= 1; j--)
			{
				if (p[i][j] > 0) p[i][j] = p[i][j]/p[i][j-1];
				else p[i][j] = 0;
			}
		}

		if ((ll)m >= (((ll)1)<<(q*2)) )
			ans = 1.0;
		else
		{
			n = 0;
			ans = 0;
			used.clear();
			isused(0);
			double d = 1;
			FI(i,0,q) d *= p[i][0];
			add(d, 0);
			FI(i,0,m)
			{
				double baka = a[1];
				ans += a[1];
				ll y = z[1];
				del();
				FI(i,0,q)
				{
					if ((y & full[i]) != full[i])
					{
						ll v = y+unit[i];
						if (!isused(v))
						{
							int u = (y>>(i*2))%4;
							double d = baka*p[i][u+1];
							add(d, v);
						}
					}
				}
			}
		}
		
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
