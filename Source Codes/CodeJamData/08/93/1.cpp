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

//C-small-attempt0.in
//C-large.in
FILE *Fin = fopen("C-large.in","r");
FILE *Fou = fopen("c.out","w");
//FILE *Fou = stdout;

int n,m;
int map[60][60];
bool heart[60][60];

int main()
{
	int i,j,k,caseN;
	fscanf(Fin,"%d",&caseN);
	for (int tt=1; tt<=caseN; tt++)
	{
		fscanf(Fin,"%d%d",&n,&m);
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				fscanf(Fin,"%d",map[i]+j);
		memset(heart,0,sizeof(heart));

		if (m%3==0)
		{
			for (i=0; i<n; i++)
				for (j=0; j<m; j++)
					if (j%3==1)
						heart[i][j] = 1;
		} else
		{
			for (i=0; i<n; i++)
				for (j=0; j<m; j++)
					if (j%3==0)
						heart[i][j] = 1;
		}
		int tot = 0;
		if (n%3==0)
		{
			for (i=0; i<n; i++) if (i%3==1)
				for (j=0; j<m; j++) if (heart[i][j])
					tot += map[i][j];
		} else
		{
			for (i=0; i<n; i++) if (i%3==0)
				for (j=0; j<m; j++) if (heart[i][j])
					tot += map[i][j];
		}
		int within = 0;
		if (n%3==0)
		{
			for (i=0; i<(n-1)/2; i+=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
			for (i=n-1; i>=(n-1)/2; i-=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
		} else if (n%3==2)
		{
			for (i=1; i<(n-1)/2; i+=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
			for (i=n-2; i>=(n-1)/2; i-=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
		}

		if (n%3!=1)
			fprintf(Fou,"Case #%d: %d\n",tt,within - tot);
		else
		{
			for (i=1; i<(n-1)/2; i+=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
			for (i=n-2; i>=(n-1)/2; i-=3)
				for (j=0; j<m; j++) if (heart[i][j])
					within += map[i][j];
			fprintf(Fou,"Case #%d: %d\n",tt,tot-within);
		}
	}
	return 0;
}

