#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctime>
 
using namespace std;

#define ABS(x) ((x) > 0 ? (x) : -(x))
#define GMAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define GMIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define RP(a,h) for(a=0; a<(h); a++)
#define FR(a,l,h) for(a=(l); a<=(h); a++)
#define SZ(a) (LL)a.size()
#define ALL(a) a.begin(), a.end()
#define pb push_back
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <VI> VVI;
typedef queue <VVI> QVVI;
typedef pair<int, int> PII;
#define LL long long
#define INF 1000000
const double PI = cos(-1.0);
int hx[4]={-1, 0, 0, 1};
int hy[4]={0, -1, 1, 0};
/*-----------------------------------------------------------------------------------------------------------------------------*/
const int MAXS = 5;
int ans;
int M, N, m, n;
vector<VI> a;
bool cache[11][11][11][11][11];
QVVI q;
queue<int> step;

bool ok(int x, int y)
{
	if (x<0 || x>=N || y<0 || y>=M) return false;
	return true;
}

int GET(VVI w, int x, int y)
{
	if (!ok(x, y)) return 0;
	return w[x][y];
}

VVI getNext(VVI cur)
{
	VVI res = cur;
	int i, j, k;
	RP(i, N) RP(j, M) if (cur[i][j]>0 && (i!=n||j!=m))
	{
		int best=-1, lk=-1;
		RP(k, 4)
			if (ok(i+hx[k], j+hy[k]))
			{
				int v=GET(cur, i+hx[k], j+hy[k]);
				if (v>best)
				{
					best=v;
					lk=k;
				}
			}
		if (lk!=-1)
		{
			res[i+hx[lk]][j+hy[lk]] = GMAX(0, res[i+hx[lk]][j+hy[lk]]-cur[i][j]);
		}
	}
	return res;
}

void pushMore(VVI next, int st)
{
	//if (cache[GET(next, n, m)][GET(next, n+hx[0], m+hy[0])][GET(next, n+hx[1], m+hy[1])][GET(next, n+hx[2], m+hy[2])][GET(next, n+hx[3], m+hy[3])]==false)
	{
		//if (next[0][0]==1)
		//	if (next[0][1]==1)
		//		if (next[0][2]==0)
		//			if (next[0][3]==0)
		//				next[0][0]=1;
		q.push(next);
		step.push(st);
		//cache[GET(next, n, m)][GET(next, n+hx[0], m+hy[0])][GET(next, n+hx[1], m+hy[1])][GET(next, n+hx[2], m+hy[2])][GET(next, n+hx[3], m+hy[3])]=true;
	}
}

void solve()
{
	while (!q.empty()) q.pop();
	while (!step.empty()) step.pop();

	q.push(a);
	step.push(0);
	//cache[GET(a, n, m)][GET(a, n+hx[0], m+hy[0])][GET(a, n+hx[1], m+hy[1])][GET(a, n+hx[2], m+hy[2])][GET(a, n+hx[3], m+hy[3])]=true;

	int k;

	while (!q.empty())
	{
		VVI cur = q.front(); q.pop();
		VVI bufnext = getNext(cur);
		VVI next;
		int curStep = step.front(); step.pop();

		//if (curStep==4)
			//curStep=curStep;
		ans = GMAX(ans, curStep);

		if (cur[n][m]>0)
		{
			bool noenemy=true;
			RP(k, 4) if (GET(cur, n+hx[k], m+hy[k])>0) { noenemy=false; break; }
			if (noenemy)
			{
				ans=-1;
				return;
			}

			// donothing
			next=bufnext;
			pushMore(next, curStep+1);

			// try 4 dirs
			RP(k, 4) if (GET(cur, n+hx[k], m+hy[k])>0)
			{
				next=bufnext;
				next[n+hx[k]][m+hy[k]] = GMAX(0, next[n+hx[k]][m+hy[k]] - cur[n][m]);

				pushMore(next, curStep+1);
			}
		}
	}
}

void process()
{
	cin >> M >> N >> m >> n;
	memset(cache, false, sizeof(cache));
	a.clear();
	int i, j, x;
	RP(i, N)
	{
		VI w;
		RP(j, M) { cin >> x; w.pb(x); }
		a.pb(w);
	}

	n--;
	m--;
	solve();
}

int main()
{
	//freopen("Round 4\\B\\sampleB.in", "r", stdin);
	//freopen("Round 4\\B\\sampleB.out", "w", stdout);
	
	freopen("Round 4\\B\\B-small-attempt2.in", "r", stdin);
	freopen("Round 4\\B\\B-small-attempt2.out", "w", stdout);

	//freopen("Round 4\\B\\B-large.in", "r", stdin);
	//freopen("Round 4\\B\\B-large.out", "w", stdout);

	int numtest, test;
	cin >> numtest;

	RP(test, numtest)
	{
		ans=0;
		process();
		
		if (ans==-1)
		{
			cout << "Case #" << (test+1) << ": " << "forever" << endl;
		}
		else
		{
			cout << "Case #" << (test+1) << ": " << ans-1 << " day(s)" << endl;
		}
	}
	return 0;
}
