#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <math.h>
#include <stdio.h>

FILE *Fin = fopen("C-small-attempt1.in","r");
//FILE *Fou = stdout;
FILE *Fou = fopen("b.out","w");

int n,m;
long double p, X;

vector<pair<pair<long double, long double>, long double> > res[20];

long double check(int left, long double x)
{
	/*if (x>=1000000) return 1;
	if (left==0)
		return 0;
	if (1000000.0/ (1<<left) > x) return 0;
	if (left==1)
	{
		if (x>=500000-1e-3) return p;
		else return 0;
	}

	long double l = 0, r = x;
	if (1000000.0/ (1<<left-1) > x)
		l = 1000000.0/ (1<<left-1) - x;
	if (x>=500000) r = 1000000.1-x;
	while (fabs(r-l)>1e-5)
	{
		long double mid1 = (l*2+r)/3;
		long double v1 = check(left-1, x-mid1) * (1-p) + check(left-1,x+mid1) * p;
		long double mid2 = (l+r*2)/3;
		long double v2 = check(left-1, x-mid2) * (1-p) + check(left-1,x+mid2) * p;
		if (v1>v2)
			l = mid1;
		else
			r = mid2;
	}
	//printf("%.6llf\n",l);
	return check(left-1, x-l) * (1-p) + check(left-1,x+l) * p;*/
	vector<long double> sx;
	for (int i=0; i<res[left-1].size(); i++)
		sx.push_back(res[left-1][i].first.first);
	vector<long double> consider;
	if (x>=5*1e5)
		consider.push_back(1e6 - x);
	else
		consider.push_back(x);
	for (int i=0; i<sx.size(); i++)
	{
		long double tmp = fabs(sx[i]-x);
		if (tmp<=x+1e-6) consider.push_back(tmp);
	}

	long double final = 0;
	for (int i=0; i<consider.size(); i++)
	{
		long double cur = 0;
		long double x1 = x-consider[i];
		for (int j=0; j<res[left-1].size(); j++)
			if (x1>=res[left-1][j].first.first-1e-7 && x1<=res[left-1][j].first.second-1e-7)
			{
				cur += res[left-1][j].second * (1-p);
				break;
			}
		x1 = x+consider[i];
		for (int j=0; j<res[left-1].size(); j++)
			if (x1>=res[left-1][j].first.first-1e-7 && x1<=res[left-1][j].first.second-1e-7)
			{
				cur += res[left-1][j].second * p;
				break;
			}
		if (cur>final) final = cur;
	}
	return final;
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int t=1; t<=caseN; t++)
	{
		printf("%d\n",t);
		double a,b;
		fscanf(Fin,"%d%lf%lf",&n,&a,&b);
		p=a; X=b;
		for (int i=0; i<20; i++)
			res[i].clear();
		res[1].push_back(make_pair(make_pair(0, 500000), 0));
		res[1].push_back(make_pair(make_pair(500000, 1000000), p));
		res[1].push_back(make_pair(make_pair(1000000, 1e20), 1));
		for (int i=2; i<=n; i++)
		{
			long double left = 0;
			while (fabs(left-1e6)>1e-7)
			{
				long double cur = check(i, left+1e-5);
				long double l = left, r = 1000000;
				while (fabs(r-l)>1e-7)
				{
					long double mid = (l+r)/2;
					if ( fabs(check(i, mid) - cur) <= 1e-10 )
						l = mid;
					else
						r = mid;
				}
				res[i].push_back(make_pair(make_pair(left, l), cur));
				left = l;
			}
			res[i].push_back(make_pair(make_pair(1000000, 1e20), 1));
		}
		for (int i=0; i<res[n].size(); i++)
			if (X>=res[n][i].first.first-1e-7 && X<=res[n][i].first.second-1e-7)
			{
				fprintf(Fou,"Case #%d: %.6llf\n",t,res[n][i].second);
				break;
			}
	}
	return 0;
}
