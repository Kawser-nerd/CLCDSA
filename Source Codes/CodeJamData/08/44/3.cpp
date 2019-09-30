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

const int maxsize=50000+5;

int n,nblock;
char str[maxsize];
int A[maxsize][16],C[16][16];
int f[two(16)][16];

int solve(int used,int last,int final)
{
	if (used==two(n)-1) return C[last][final];
	int &ret=f[used][last];
	if (ret!=-1) return ret;
	ret=1000000;
	for (int i=0;i<n;i++) if (!contain(used,i))
		checkmin(ret,solve(used+two(i),i,final)+C[last][i]);
	return ret;
}
int main()
{
//	freopen("..\\input.txt","r",stdin);
//	freopen("..\\D-small-attempt0.in","r",stdin);freopen("..\\D-small-attempt0.out","w",stdout);
	freopen("..\\D-large.in","r",stdin);freopen("..\\D-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: ",caseId);
		scanf("%d",&n);
		scanf("%s",str);
		nblock=strlen(str)/n;
		for (int i=0;i<nblock;i++)
			for (int k=0;k<n;k++)
				A[i][k]=(str[i*n+k]-'a');
		memset(C,0,sizeof(C));
		for (int p0=0;p0<n;p0++)
			for (int p1=0;p1<n;p1++)
				for (int i=0;i<nblock;i++)
					C[p0][p1]+=(int)(A[i][p0]!=A[i][p1]);
		int ret=10000000;
		for (int p0=0;p0<n;p0++)
			for (int p1=0;p1<n;p1++) if (p0!=p1)
			{
				int cost=0;
				for (int i=0;i<nblock-1;i++)
					cost+=(int)(A[i][p1]!=A[i+1][p0]);
				memset(f,255,sizeof(f));
				int tmp=solve(two(p0)+two(p1),p0,p1);
				checkmin(ret,cost+tmp);
			}
		printf("%d\n",ret+1);
		fflush(stdout);
	}
}