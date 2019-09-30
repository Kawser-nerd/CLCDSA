#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <assert.h>

#pragma warning(disable:4996)
using namespace std;

#define TIME fprintf(stderr,"\n-----------\ntime : %.2f sec\n",double(clock())/CLOCKS_PER_SEC);
#define EXIT exit(0);
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w",stdout);

#define M 0
#define MOD 0
#define ADD(_X,_Y) _X=(_X+_Y)%MOD;

#define abs(_Z) (((_Z)<0)?-(_Z):(_Z))
#define f0(_X,_Y) for(_X=0;_X<_Y;++_X)
#define f1(_X,_Y) for(_X=1;_X<=_Y;++_X)
#define ff(_X,_Y,_Z) for(_X=_Y;_X<=_Z;++_X)
#define fF(_X,_Y,_Z) for(_X=_Y;_X<_Z;++_X)
#define pb push_back
#define sz(_X) _X.size()
typedef long long ll;
const double PI=atan2(1.,0);
const int DY[]={0,1,0,-1},DX[]={1,0,-1,0};

struct XY{int x,y;
	XY(int _X=0,int _Y=0){x=_X;y=_Y;}
	bool operator == (const XY &p) const{return x==p.x && y==p.y;}
	bool operator < (const XY &p) const{if(x!=p.x) return x<p.x; return y<p.y;}
	XY operator + (const XY &p) const{return XY(x+p.x,y+p.y);}
	XY operator - (const XY &p) const{return XY(x-p.x,y-p.y);}
	XY operator - () const{return XY(-x,-y);}
	ll norm() const{return (ll)x*x+(ll)y*y;}
};
int ccw(const XY &p,const XY &q,const XY &r){ll _X=(ll)p.x*q.y+(ll)q.x*r.y+(ll)r.x*p.y-((ll)p.y*q.x+(ll)q.y*r.x+(ll)r.y*p.x); if(_X<0) return -1; return _X>0;}

char convert[255],a[110],b[110];
int main()
{
	int i,k,t;

	FIN
	FOUT

	scanf("%d%*c",&t);

	convert['a']='y';
	convert['b']='h';
	convert['c']='e';
	convert['d']='s';
	convert['e']='o';
	convert['f']='c';
	convert['g']='v';
	convert['h']='x';
	convert['i']='d';
	convert['j']='u';
	convert['k']='i';
	convert['l']='g';
	convert['m']='l';
	convert['n']='b';
	convert['o']='k';
	convert['p']='r';
	convert['q']='z';
	convert['r']='t';
	convert['s']='n';
	convert['t']='w';
	convert['u']='j';
	convert['v']='p';
	convert['w']='f';
	convert['x']='m';
	convert['y']='a';
	convert['z']='q';

	f1(k,t)
	{
		gets(a);
		for(i=0;a[i];++i) if(a[i]>='a' && a[i]<='z') a[i]=convert[a[i]];
		printf("Case #%d: %s\n",k,a);
	}
	//f0(i,26)
	//{
	//	printf("convert['%c']='%c';\n",i+'a',convert[i+'a']);
	//}
	return 0;
}
