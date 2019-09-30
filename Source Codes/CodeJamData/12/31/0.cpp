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
#define LIM 1000

int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	int N;
	int i,j,k;
	static int ncon[LIM],con[LIM][10];
	static bool vis[LIM];
	queue <int> Q;
	//testcase loop
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d: ",tt+1);
				while (!Q.empty())
					Q.pop();
			//input
			scanf("%d",&N);
				For(i,N)
				{
					scanf("%d",&ncon[i]);
						For(j,ncon[i])
							scanf("%d",&con[i][j]),con[i][j]--;
				}
			//look for diamonds...
				For(k,N)
				{
					Fill(vis,0);
					Q.push(k);
						while (!Q.empty())
						{
							i=Q.front(),Q.pop();
								if (vis[i])
								{
									printf("Yes\n");
									goto Done;
								}
							vis[i]=1;
								For(j,ncon[i])
									Q.push(con[i][j]);
						}
				}
			printf("No\n");
Done:;
		}
	return(0);
}