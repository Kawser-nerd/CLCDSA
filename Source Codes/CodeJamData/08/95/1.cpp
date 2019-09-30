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

//E-small-attempt0.in
//E-large.in
FILE *Fin = fopen("E-large.in","r");
FILE *Fou = fopen("e.out","w");
//FILE *Fou = stdout;

int n,m;
char map[60][60];
const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

inline bool valid(int a, int b)
{ return a>=0&&a<n&&b>=0&&b<m; }

int nid = 0;
int idt[100][100];
int pos[3000][2];
int c[3000];
vector<int> net[3000];
bool hash[3000];
int done[3000][2];

bool path(int u)
{
	if (hash[u]) return false;
	hash[u] = true;
	for (int i=0; i<net[u].size(); i++)
	{
		int v = net[u][i];
		if (done[v][0]==u||done[v][1]==u) continue;
		if (done[v][0]==0)
		{
			done[v][0] = u;
			return true;
		}
		if (c[v]==2 && done[v][1]==0)
		{
			done[v][1] = u;
			return true;
		}
		if (path(done[v][0]))
		{
			done[v][0] = u;
			return true;
		}
		if (c[v]==2 && path(done[v][1]))
		{
			done[v][1] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int tt=1; tt<=caseN; tt++)
	{
		fscanf(Fin,"%d%d",&n,&m);
		for (i=0; i<n; i++)
			fscanf(Fin,"%s",map[i]);
		/*if (tt==80)
		{
			for (i=0; i<n; i++)
				fprintf(stderr,"%s\n",map[i]);
		}*/
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (map[i][j]=='?')
				{
					int t = 0;
					for (k=0; k<4; k++)
					{
						int x = i+d[k][0], y = j+d[k][1];
						if (valid(x,y) && map[x][y]=='#')
							t++;
					}
					if (t>=2)
						map[i][j] = '.';
				}
			/*for (i=0; i<n; i++)
				fprintf(stderr,"%s\n",map[i]);*/

		nid = 0;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (map[i][j]=='?')
				{
					idt[i][j] = ++nid;
					pos[nid][0] = i;
					pos[nid][1] = j;
				}
		for (i=1; i<=nid; i++)
			net[i].clear();
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (map[i][j]=='?')
				{
					int u = idt[i][j];
					int t = 0;
					for (k=0; k<4; k++)
					{
						int x = i+d[k][0], y = j+d[k][1];
						if (valid(x,y) && map[x][y]=='#')
							t++;
					}
					c[u] = 2 - t;
					for (k=0; k<4; k++)
					{
						int x = i+d[k][0], y = j+d[k][1];
						if (valid(x,y) && map[x][y]=='?')
							net[u].push_back(idt[x][y]);
					}
				}
		int ans = 0;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if (map[i][j]=='#')
				{
					int t = 0;
					for (k=0; k<4; k++)
					{
						int x = i+d[k][0], y = j+d[k][1];
						if (valid(x,y) && map[x][y]=='#')
							t++;
					}
					ans += 4-t;
				}
		for (i=1; i<=nid; i++)
			ans += c[i]*2;
		memset(done,0,sizeof(done));
		memset(hash,0,sizeof(hash));
		for (i=1; i<=nid; i++) if ((pos[i][0]+pos[i][1])%2==0)
		{
			while (c[i] && path(i))
			{
				ans-=2;
				memset(hash,0,sizeof(hash));
				c[i]--;
			}
		}


		/*int bakans = ans;
		char netmap[60][60];
		ans = 0x80000000;
		for (int s=0; s<(1<<m); s++)
		{
			memcpy(netmap,map,sizeof(map));
			for (i=0; i<m; i++)
				if (map[0][i]=='?')
					if (s&(1<<i))
						netmap[0][i]='#';
					else
						netmap[0][i]='.';
			for (i=1; i<n; i++)
				for (j=0; j<m; j++) if (netmap[i][j]=='?')
				{
					int t = 0;
					for (k=0; k<4; k++)
					{
						int x = i+d[k][0], y = j+d[k][1];
						if (valid(x,y) && netmap[x][y]=='#')
							t++;
					}
					if (t<=1)
						netmap[i][j]='#';
					else
						netmap[i][j]='.';
				}
			int cur = 0;
			for (i=0; i<n; i++)
				for (j=0; j<m; j++)
					if (netmap[i][j]=='#')
					{
						int t = 0;
						for (k=0; k<4; k++)
						{
							int x = i+d[k][0], y = j+d[k][1];
							if (valid(x,y) && netmap[x][y]=='#')
								t++;
						}
						cur += 4-t;
					}
			if (cur>ans) ans = cur;
		}
		if (ans>bakans)
			fprintf(stderr,"WARN %d!\n",tt);*/
		fprintf(Fou,"Case #%d: %d\n",tt, ans);
		printf("Case #%d: %d\n",tt, ans);
	}
	return 0;
}

