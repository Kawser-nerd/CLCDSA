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

//A-small-attempt0.in
//A-large.in
FILE *Fin = fopen("A-large.in","r");
FILE *Fou = fopen("a.out","w");
//FILE *Fou = stdout;

int n,m;

struct Point
{
	int a,b,c;
} p[6000];
bool operator < (Point x, Point y)
{ return x.b<y.b || x.b==y.b && x.c<y.c; }

int lowbit[20000];
int tree[12000];
void put(int u)
{
	for (; u<12000; u+=1<<lowbit[u]-1)
		tree[u]++;
}
int get(int u)
{
	int ans = 0;
	for (; u>0; u-=1<<lowbit[u]-1)
		ans += tree[u];
	return ans;
}

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	memset(lowbit,0,sizeof(lowbit));
	for (i=0; i<20; i++)
		for (j=0; j<20000; j+=(1<<i))
			lowbit[j]++;
	for (int tt=1; tt<=caseN; tt++)
	{
		fscanf(Fin,"%d",&n);
		for (i=0; i<n; i++)
		{
			fscanf(Fin,"%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		}
		int best = 0;
		sort(p, p+n);
		for (k=0; k<=10000; k++)
		{
			memset(tree,0,sizeof(tree));
			for (i=0; i<n; i++) if (p[i].a<=k && p[i].b+p[i].c<=10000-k)
			{
				put(p[i].c+1);
				int count = get(10000-k-p[i].b+1);
/*				int count = 1;
				for (j=0; j<i; j++) if (p[j].a<=k && p[j].c<=10000-k-p[i].b )
					count++;*/
				if (count>best) best = count;
			}
		}
		fprintf(Fou,"Case #%d: %d\n",tt,best);
		printf("Case #%d: %d\n",tt,best);
	}
	return 0;
}

