#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0
#define LIMN 2000
#define LIMA 250

int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	LD D;
	int N,A;
	int i,j;
	LD r1,r2,m,s;
	static LD cx[LIMN],cy[LIMN];
	static LD acc[LIMA];
	//testcase loop
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d:\n",tt+1);
			//input
			scanf("%Lf%d%d",&D,&N,&A);
				For(i,N)
					scanf("%Lf %Lf",&cx[i],&cy[i]);
				For(i,A)
					scanf("%Lf",&acc[i]);
			//ignore car past destination
				For(i,N)
					if (cy[i]>D)
					{
						s=(cx[i]-cx[i-1])/(cy[i]-cy[i-1]);
						cy[i]=D;
						cx[i]=cx[i-1] + s*(cy[i]-cy[i-1]);
						N=i+1;
						break;
					}
			//answer each query
				For(i,A)
				{
					//binary search on when to leave
					r1=0,r2=100000;
						while (r2>r1+EPS)
						{
							//get middle
							m=(r1+r2)/2;
							//try leaving here
								For(j,N)
									if ((cx[j]>m) && (0.5*acc[i]*Sqr(cx[j]-m)>cy[j]+EPS))
										goto Bad;
							//good - go earlier
							r2=m;
							continue;
							//bad - go later
Bad:;
							r1=m;
						}
					//output
					printf("%.7Lf\n",r1 + sqrt(2*D/acc[i]));
				}
		}
	return(0);
}