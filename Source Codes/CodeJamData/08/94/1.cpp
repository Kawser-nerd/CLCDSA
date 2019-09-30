#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define prr make_pair
typedef long long ll;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
inline double hypot(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}//NOTES:dist(
inline double hypot2(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}//NOTES:distR(
inline bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase(
inline bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase(
inline bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
inline bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
inline char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase(
inline char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase(

//D-small-attempt0.in
//D-large.in
FILE *Fin = fopen("D-large.in","r");
FILE *Fou = fopen("d.out","w");
//FILE *Fou = stdout;

int n,m;
char map[100][100];
int mindis[100][100];
int dis[40][40][40][40];
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int idt[40][40];
int nid;

int cc[1000][1000];

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int tt=1; tt<=caseN; tt++)
	{
		fscanf(Fin,"%d%d",&n,&m);
		for (i=0; i<n; i++)
			fscanf(Fin,"%s",map[i]);

		memset(dis,0x7F,sizeof(dis));
		for (i=0; i<n; i++) for (j=0; j<m; j++) if (map[i][j]!='.')
		{
			dis[i][j][i][j] = 0;
			vector<pair<int, int> > bfs;
			bfs.push_back(prr(i,j));
			for (int t=0; t<bfs.size(); t++)
			{
				int u = bfs[t].first, v = bfs[t].second;
				for (k=0; k<4; k++)
				{
					int nu = u+d[k][0], nv = v+d[k][1];
					if (u+d[k][0]>=0&&u+d[k][0]<n && v+d[k][1]>=0&&v+d[k][1]<m && map[u+d[k][0]][v+d[k][1]]!='.')
					{
						if (dis[i][j][u][v] + 1 < dis[i][j][nu][nv])
						{
							dis[i][j][nu][nv] = dis[i][j][u][v]+1;
							bfs.push_back(prr(nu,nv));
						}
					}
				}
			}
		}

		memset(mindis,0x7F,sizeof(mindis));
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (map[i][j]=='T')
					mindis[i][j] = 0;
				else if (map[i][j]=='#')
				{
					mindis[i][j] = 0x7F7F7F7F;
					for (int i1=0; i1<n; i1++)
						for (int j1=0; j1<m; j1++) if (map[i1][j1]=='T' && dis[i][j][i1][j1]<mindis[i][j])
							mindis[i][j] = dis[i][j][i1][j1];
				}
		int ans = 0;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++) if (map[i][j]=='#')
				ans += mindis[i][j];
		nid = 0;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++) if (map[i][j]=='T')
				idt[i][j] = ++nid;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++) if (map[i][j]=='T')
				for (int i1=0; i1<n; i1++)
					for (int j1=0; j1<m; j1++) if (map[i1][j1]=='T')
					{
						int cur = dis[i][j][i1][j1], cost;
						int mid = cur/2;
						if (cur&1)
						{
							cost = cur * (cur+1)/2 - mid*(mid+1)/2 - mid*(mid+1)/2;
						}
						else
						{
							cost = cur * (cur+1)/2 - mid*(mid+1)/2 - mid*(mid-1)/2;
						}
						cc[idt[i][j]][idt[i1][j1]] = cost;
					}

		bool ins[1000]; int ss[1000];
		memset(ins,0,sizeof(ins));
		ins[1] = true;
		for (i=2; i<=nid; i++)
			ss[i] = cc[1][i];
		for (i=1; i<nid; i++)
		{
			int min = 0x7FFFFFFF, dir;
			for (j=1; j<=nid; j++) if (!ins[j] && ss[j]<min)
				min = ss[j], dir = j;
			ins[dir] = true;
			ans += min;
			for (j=1; j<=nid; j++)
				if (cc[dir][j]<ss[j])
					ss[j] = cc[dir][j];
		}

		fprintf(Fou,"Case #%d: %d\n",tt, ans);
		printf("Case #%d: %d\n",tt, ans);
	}
	return 0;
}

