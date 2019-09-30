#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-large"

#define N 1024
int n;

const LL sz = 50000000000000000LL;

struct Rect{
	LL x1,y1,x2,y2;
	bool empty() {
		return x1 > x2 || y1>y2;
	}
	vector<pair<LL,LL> > corners()
	{
		vector<pair<LL,LL> > res;
		res.pb(make_pair(x1,y1));
		res.pb(make_pair(x1,y2));
		res.pb(make_pair(x2,y1));
		res.pb(make_pair(x2,y2));
		return res;
	}
};

Rect inter(Rect a, Rect b)
{
	Rect r = {max(a.x1,b.x1),max(a.y1,b.y1),min(a.x2,b.x2),min(a.y2,b.y2)};
	return r;
}

vector<Rect> intersect(vector<Rect> a, vector<Rect> b)
{
	vector<Rect> res;
	REP(i,SZ(a)) REP(j,SZ(b))
	{
		Rect r = inter(a[i],b[j]);
		if (!r.empty())
			res.pb(r);
	}
	return res;
}

vector<Rect> a[2][2];
bool hasres;
LL rx,ry;

LL sx[1024],sy[1024];
char sval[1024];

#define OUT 4

vector<pair<LL,LL>> tmp;

void go(LL x, LL y)
{
	tmp.pb(make_pair(x,y));
}

void go222(LL x, LL y) {
	//printf("?? %lld %lld\n",x,y);
	FOR(dx,-OUT,OUT) FOR(dy,-OUT,OUT)
	{
		LL xx = x+dx;
		LL yy = y+dy;
		REP(i,n)
			if ((max(abs(xx-sx[i]),abs(yy-sy[i]))%2 ? '#' : '.') != sval[i])
				goto bad;
		if (!hasres || abs(xx)+abs(yy) < abs(rx)+abs(ry) || abs(xx)+abs(yy) == abs(rx)+abs(ry) && (xx > rx || xx == rx && yy > ry))
		{
			rx = xx;
			ry = yy;
			hasres = true;
		}
		bad:;
	}
}

void gozz(LL zx, LL zy)
{
	LL y = (zx+zy)/2;
	LL x = zx-y;
	go(x,y);
	go(x,0);
	go(0,y);
}

void goss(LL t)
{
	gozz(t,t);
	gozz(t,-t);
	gozz(-t,t);
	gozz(-t,-t);
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"%d\n",test);
		scanf("%d",&n);
		REP(i,2) REP(j,2)
		{
			Rect all = {-sz,-sz,sz,sz};
			a[i][j].clear();
			a[i][j].pb(all);
		}
		REP(i,n)
		{
			LL x,y;
			cin >> x >> y;
			sx[i] = x;
			sy[i] = y;
			char val = 0;
			do val = getc(stdin); while (val!='#'&&val!='.');
			sval[i] = val;
			int mx = abs(x)%2 ^ (val=='.');
			int my = abs(y)%2 ^ (val=='.');
			a[mx][my].clear();
			LL xz = x+y;
			LL yz = y-x;
			{
				Rect r1	= {xz+1,-sz,sz,yz-1};
				Rect r2	= {-sz,yz+1,xz-1,sz};
				vector<Rect> rr; rr.pb(r1); rr.pb(r2);
				a[mx^1][my] = intersect(a[mx^1][my],rr);
			}
			{
				Rect r1	= {xz+1,yz+1,sz,sz};
				Rect r2	= {-sz,-sz,xz-1,yz-1};
				vector<Rect> rr; rr.pb(r1); rr.pb(r2);
				a[mx][my^1] = intersect(a[mx][my^1],rr);
			}
		}
		hasres = false;
		tmp.clear();
		go(0,0);
		REP(mx,2) REP(my,2)
		{
			REP(i,SZ(a[mx][my]))
			{
				vector<pair<LL,LL> > bb = a[mx][my][i].corners();
				REP(j,SZ(bb))
				{
					LL zx = bb[j].X;
					LL zy = bb[j].Y;
					gozz(zx,zy);
					goss(zx);
					goss(zy);
				}
			}
		}
		UNIQUE(tmp);
		REP(i,SZ(tmp))
			go222(tmp[i].X,tmp[i].Y);
		printf("Case #%d: ",test);
		if (hasres)
			printf("%lld %lld\n",rx,ry);
		else
			printf("Too damaged\n");
	}
/*#define T 20
	FOR(x,-T,T) if (abs(x)%2 == 1)
	{
		FOR(y,-T,T) if (abs(y)%2 == 0)
			printf("%c", (x==0&&y==0) ? '*' : (max(abs(x),abs(y))%2?'#':'.'));
		printf("\n");
	}/**/
	return 0;
}