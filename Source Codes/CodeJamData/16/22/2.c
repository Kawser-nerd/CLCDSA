#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string a,b;
string ra,rb;
long long calc(int p, long long d)
{
	string ta,tb;
	if (p >= a.size())
		return d;
	if (d > 0)
	{
		long long r = d;
		for(int i=p; i<a.size(); i++)
		{
			if (a[i] == '?') ra[i] = '0';
			if (b[i] == '?') rb[i] = '9';
			d = d*10 + (ra[i] - rb[i]);
		}
		return d;
	}
	if (d < 0)
	{
		long long r = d;
		for(int i=p; i<a.size(); i++)
		{
			if (a[i] == '?') ra[i] = '9';
			if (b[i] == '?') rb[i] = '0';
			d = d*10 + (ra[i] - rb[i]);
		}
		return d;
	}
	if (a[p] != '?' && b[p] != '?')
	{
		ra[p] = a[p]; rb[p] = b[p];
		return calc(p+1, d*10+(a[p]-b[p]));
	}
	if (a[p] == '?' && b[p] == '?')
	{
		long long best = 9e18;
		long long d1 = calc(p+1, d*10);
		ra[p] = rb[p] = '0'; best = d1;

		ta = ra; tb = rb;
		long long d3 = calc(p+1, d*10-1);
		if (abs(d3) < abs(best))
		{
			ra[p] = '0'; rb[p] = '1'; best = d3;
		}
		else
		{
			ra = ta; rb = tb;
		}

		ta = ra; tb = rb;
		long long d2 = calc(p+1, d*10+1);
		if (abs(d2) < abs(best))
		{
			ra[p] = '1'; rb[p] = '0'; best = d2;
		}
		else
		{
			ra = ta; rb = tb;
		}
		return best;
	}
	if (a[p] == '?' && b[p] != '?')
	{
		long long best = 9e18;

		if (b[p] > '0')
		{
			long long d1 = calc(p+1, d*10-1);
			if (abs(d1) < abs(best))
			{
				ra[p] = b[p]-1; rb[p] = b[p]; best = d1;
			}
		}

		ta = ra; tb = rb;
		long long d2 = calc(p+1, d*10);
		if (abs(d2) < abs(best))
		{
			ra[p] = rb[p] = b[p]; best = d2;
		}
		else
		{
			ra = ta; rb = tb;
		}

		if (b[p] < '9')
		{
			ta = ra; tb = rb;
			long long d3 = calc(p+1, d*10+1);
			if (abs(d3) < abs(best))
			{
				ra[p] = b[p]+1; rb[p] = b[p];
				best = d3;
			}
			else
			{
				ra = ta; rb = tb;
			}
		}
		return best;
	}
	if (a[p] != '?' && b[p] == '?')
	{
		long long best = 9e18;
		if (a[p] > '0')
		{
			long long d1 = calc(p+1, d*10+1);
			if (abs(d1) < abs(best))
			{
				ra[p] = a[p]; rb[p] = a[p]-1; best = d1;
			}
		}
		ta = ra; tb = rb;
		long long d2 = calc(p+1, d*10);
		if (abs(d2) < abs(best))
		{
			ra[p] = rb[p] = a[p]; best = d2;
		}
		else
		{
			ra = ta; rb = tb;
		}
		if (a[p] < '9')
		{
			ta = ra; tb = rb;
			long long d3 = calc(p+1, d*10-1);
			if (abs(d3) < abs(best))
			{
				ra[p] = a[p]; rb[p] = a[p]+1; best = d3;
			}
			else
			{
				ra = ta; rb = tb;
			}
		}
		return best;
	}
	return 0;
}

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> a;
		cin >> b;
		ra = a; rb = b;
		calc(0,0);
		printf("Case #%d: %s %s\n", cc, ra.c_str(), rb.c_str());
	}
}
