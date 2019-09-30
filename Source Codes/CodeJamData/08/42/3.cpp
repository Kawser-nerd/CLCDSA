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

int size,lst[2000000];

bool check(int exp,int n,int m,int &A,int &B)
{
	if (n>m) return check(exp,m,n,B,A);
	if (exp==0) 
	{
		A=B=0;
		return true;
	}
	for (int i=1;i<=n;i++) if (exp%i==0 && exp/i<=m) 
	{
		A=i;
		B=exp/i;
		return true;
	}
	return false;
}
bool solve(int n,int m,int exp,int &A,int &D,int &C,int &B)
{
	if ((n+1)*(m+1)>1000000)
	{
		for (int step=0;exp+step<=n*m;step++)
			if (check(exp+step,n,m,A,B) && check(step,n,m,C,D))
				return true;
		return false;
	}
	size=0;
	for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) lst[size++]=i*j;
	sort(lst,lst+size);
	int k=0;
	for (int i=0;i<size;i++)
	{
		for (;k<size && lst[k]-lst[i]<exp;k++);
		if (k==size) break;
		if (lst[k]-lst[i]==exp)
		{
			check(lst[k],n,m,A,B);
			check(lst[i],n,m,C,D);
			return true;
		}
	}
	return false;
}
int main()
{
//	freopen("..\\input.txt","r",stdin);
//	freopen("..\\B-small-attempt0.in","r",stdin);freopen("..\\B-small-attempt0.out","w",stdout);
	freopen("..\\B-large.in","r",stdin);
	//freopen("..\\B-large.out","w",stdout);
	FILE *f=fopen("..\\B-large.out","w");
	int testcase;
	scanf("%d",&testcase);
	int n,m,exp;
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("%d %d\n",caseId,testcase);
		fprintf(f,"Case #%d: ",caseId);
		scanf("%d%d%d",&n,&m,&exp);
		int x1,y1,x2,y2;
		if (solve(n,m,exp,x1,y1,x2,y2))
			fprintf(f,"0 0 %d %d %d %d\n",x1,y1,x2,y2);
		else
			fprintf(f,"IMPOSSIBLE\n");
		fflush(f);
	}
	fclose(f);
}