#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)

const int maxn=1000+5;

int n;
double X[maxn],Y[maxn],Z[maxn],P[maxn];

double solve(double X0,double Y0,double Z0)
{
	double result=0;
	for (int i=0;i<n;i++) 
	{
		double d=fabs(X0-X[i])+fabs(Y0-Y[i])+fabs(Z0-Z[i]);
		checkmax(result,d/P[i]);
	}
	return result;
}
int main()
{
//	freopen("..\\input.txt","r",stdin);
//	freopen("..\\C-small-attempt0.in","r",stdin);freopen("..\\C-small-attempt0.out","w",stdout);
	freopen("..\\C-large.in","r",stdin);freopen("..\\C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%lf%lf%lf%lf",&X[i],&Y[i],&Z[i],&P[i]);
		double X0=0,Y0=0,Z0=0;
		double L=1e6;
		double R0=solve(X0,Y0,Z0);
		for (int step=0;step<1000;step++)
		{
			double tmp;
			tmp=solve(X0-L,Y0,Z0);if (tmp<R0) R0=tmp,X0-=L;
			tmp=solve(X0+L,Y0,Z0);if (tmp<R0) R0=tmp,X0+=L;
			tmp=solve(X0,Y0-L,Z0);if (tmp<R0) R0=tmp,Y0-=L;
			tmp=solve(X0,Y0+L,Z0);if (tmp<R0) R0=tmp,Y0+=L;
			tmp=solve(X0,Y0,Z0-L);if (tmp<R0) R0=tmp,Z0-=L;
			tmp=solve(X0,Y0,Z0+L);if (tmp<R0) R0=tmp,Z0+=L;
			if ((step+1)%6==0) L/=1.618;
		}
		printf("%0.12lf\n",R0);
	}
}