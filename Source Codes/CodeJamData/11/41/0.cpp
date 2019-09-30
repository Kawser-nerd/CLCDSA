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
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

const int maxn=1000+5;

int n;
double length,S,R,leftTime;
double L[maxn],P[maxn];

int main()
{
//	freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		printf("Case #%d: ",case_id);
		scanf("%lf%lf%lf%lf%d",&length,&S,&R,&leftTime,&n);
		R-=S;
		double last=0;
		L[n]=0;
		P[n]=S;
		for (int i=0;i<n;i++)
		{
			double s,t,w;
			scanf("%lf%lf%lf",&s,&t,&w);
			P[i]=S+w;
			L[i]=t-s;
			L[n]+=(s-last);
			last=t;
		}
		L[n]+=length-last;
		n++;
		for (int i=0;i<n;i++) for (int j=i+1;j<n;j++)
			if (P[j]<P[i])
			{
				swap(P[i],P[j]);
				swap(L[i],L[j]);
			}
		double result=0;
		for (int i=0;i<n;i++)
		{
			double runTime=min(leftTime,L[i]/(P[i]+R));
			leftTime-=runTime;
			result+=runTime+(L[i]-(P[i]+R)*runTime)/P[i];
		}
		printf("%.18lf\n",result);
		fflush(stdout);
	}
	return 0;
}
