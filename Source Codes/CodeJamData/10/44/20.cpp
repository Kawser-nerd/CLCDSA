#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;
const double pi=3.1415926535897932384626433832795;
const double eps=1e-9;

#define pb push_back
#define mp make_pair
#define sz size()
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define FOR(i,a,b) for(int i=(a),_b(b); i<_b; ++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b); i>=_b; --i)
#define CLR(a,v) memset((a),(v),sizeof(a))
#define CPY(a,b) memcpy((a),(b),sizeof(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)<(0)?-(a):(a))
#define HAS(x,k) ((x).find(k)!=(x).end())
#define sqr(a) ((a)*(a))
//#pragma comment(linker,"/STACK:200000000")

#define PREV(x) ((x)&((x)-1))
#define NEXT(x) (((x)<<1) - PREV(x))

char ch[1<<20];
string gs(){ scanf("%s",ch); return string(ch); }
string gl(){ gets(ch); return string(ch); }



double arctan(double a)
{
	double res = atan(a);
	if (res<0) res+=pi;
	return res*2.0;
}

double solve(double x1,double y1, double r1,
			 double x2,double y2, double r2)
{
	if (ABS(r1)<1e-9 || ABS(r2)<1e-9) return 0.0;
	if (r1<r2) { swap(x1,x2); swap(y1,y2); swap(r1,r2); }
	double RESULT=0.0;
	double d = sqrt(sqr(x1-x2) + sqr(y1-y2));

	if (d>=r1+r2)
	{
		RESULT=0.0;
	}
	else
	if (d<1e-9 || r1-d>=r2) 
	{
		RESULT = pi*sqr(r2);
	}
	else
	{
		double EB = (sqr(r2)-sqr(r1)+sqr(d))/(2*d);
		double AE = d - EB;
		double CE = sqrt(sqr(r1)-sqr(AE));
		
		double S1,S2;
		
		// S of 1
		double alp = arctan(CE/AE);
		S1 = (pi*sqr(r1))*(alp/(2.0*pi));
		S1 -= (CE*AE);

		// S of 2
		if (ABS(EB)<1e-9)
		{
			S2 = (pi*sqr(r2))/2.0;
		}
		else
		{
			alp = arctan(CE/EB);
			S2 = (pi*sqr(r2))*(alp/(2.0*pi));
			S2 -= (CE*EB);
		}

		RESULT = S1+S2;
	}
	return RESULT;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int tc=0; int t; scanf("%d",&t);
	while(t--)
	{
		++tc;
		double X[116],Y[116];
		double x1,y1,x2,y2;
		int N,M;
		scanf("%d%d",&N,&M);
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		printf("Case #%d:",tc);
		FOR(i,0,M) 
		{
			double x,y; scanf("%lf%lf",&x,&y);
			double r1=hypot(x1-x,y1-y);
			double r2=hypot(x2-x,y2-y);
			printf(" %.7lf",solve(x1,y1,r1,x2,y2,r2));
		}
		printf("\n");
	}
	
	return 0;
}
