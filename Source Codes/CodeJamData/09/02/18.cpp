#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <memory.h>
#include <cstdio>
#include <complex>
//#include <ctime>
//#include <hash_map>
using namespace std;
//using namespace stdext;


typedef unsigned int uint;
typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<double,double> PII;

#define sz size()
#define pb push_back
#define mp std::make_pair
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b);i>=_b;--i)
#define ABS(a) ((a)<0?-(a):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define HAS(v,k) ((v).find(k)!=(v).end())
#define CLR(a,v) memset((a),(v),sizeof(a))
#define CPY(a,b) memcpy((a),(b),sizeof(a))
#define sqr(a) ((a)*(a))
#pragma comment(linker,"/STACK:64000000")

int gcd(int a,int b) { return (!a)?b:gcd(b%a,a); }
LL lcm(int a, int b) { return a/gcd(a,b)*b; }
const LL MOD=10000;
const LD eps  = 1e-12;

#define PREV(a) ((a)&(a-1))
#define NEXT(a) ((a<<1)-PREV(a))
typedef int matrix[128][128];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int Gx[128][128];
int Gy[128][128];
int A[128][128];
int color[128][128];
int was[20000];
int N,M;
void dfs(int x, int y, int c)
{
	if (color[x][y]!=-1) return;
	color[x][y]=c;
	FOR(k,0,4)
	{
		int nx=x+dx[k];
		int ny=y+dy[k];
		if (nx<0 || ny<0 || nx>=N || ny>=M) continue;
		if (Gx[nx][ny]==x && Gy[nx][ny]==y) 
			dfs(nx,ny,c);
	}
}

char ch[120000];
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int TC; scanf("%d",&TC);
	FOR(test,1,TC+1)
	{
		scanf("%d%d",&N,&M);
		FOR(i,0,N) FOR(j,0,M) scanf("%d",&A[i][j]);
		FOR(i,0,N) FOR(j,0,M)
		{
			int bestv=0;
			int best=-1;
			FOR(k,0,4)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				if (nx<0 || ny<0 || nx>=N || ny>=M) continue;
				if (best==-1 || A[nx][ny]<bestv) {best=k; bestv=A[nx][ny];}
			}
			if (best==-1 || bestv>=A[i][j]) {Gx[i][j]=i; Gy[i][j]=j;}
			else
			{
				int nx=i+dx[best];
				int ny=j+dy[best];	
				Gx[i][j]=nx;
				Gy[i][j]=ny;
			}
		}
		CLR(color,-1);
		int z=0;
		FOR(i,0,N) FOR(j,0,M) if (color[i][j]==-1 && Gx[i][j]==i && Gy[i][j]==j) dfs(i,j,z++);
		CLR(was,-1); int q=0;
		printf("Case #%d:\n",test);
		FOR(i,0,N) 
			FOR(j,0,M)
		{
			if (was[color[i][j]]==-1) was[color[i][j]]=q++;
			printf("%c%c",'a'+was[color[i][j]],(j==M-1)?'\n':' ');
		}
	}

	
	
	return 0;	
}
