#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-11;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
typedef pair<int,int> ipair;//NOTES:ipair
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
//Numberic Functions
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
  {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
  {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
  {if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
  {vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
//Matrix Operations
const int MaxMatrixSize=40;//NOTES:MaxMatrixSize
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j];cout<<endl;}}
template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
template<class T> inline void identityMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:identityMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=(i==j)?1:0;}
template<class T> inline void addMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];}
template<class T> inline void subMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];}
template<class T> inline void mulMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];}
template<class T> inline void addModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]+B[i][j],m);}
template<class T> inline void subModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subModMatrix(
  {for (int i=0;i<n;i++) for (int j=0;j<n;j++) C[i][j]=checkMod(A[i][j]-B[i][j],m);}
template<class T> inline T multiplyMod(T a,T b,T m) {return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));}//NOTES:multiplyMod(
template<class T> inline void mulModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulModMatrix(
  { T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) for (int k=0;k<n;k++) C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;}
template<class T> inline T powerMod(T p,int e,T m)//NOTES:powerMod(
  {if(e==0)return 1%m;else if(e%2==0){T t=powerMod(p,e/2,m);return multiplyMod(t,t,m);}else return multiplyMod(powerMod(p,e-1,m),p,m);}
//Point&Line
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}//NOTES:dist(
double distR(double x1,double y1,double x2,double y2){return sqr(x1-x2)+sqr(y1-y2);}//NOTES:distR(
template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2){return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);}//NOTES:cross(
int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)//NOTES:crossOper(
  {double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);if (fabs(t)<=eps) return 0;return (t<0)?-1:1;}
bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)//NOTES:isIntersect(
  {return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;}
bool isMiddle(double s,double m,double t){return fabs(s-m)<=eps || fabs(t-m)<=eps || (s<m)!=(t<m);}//NOTES:isMiddle(
//Translator
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase(
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase(
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase(
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase(
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}//NOTES:toString(
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt(
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toInt64(
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;}//NOTES:toDouble(
template<class T> void stoa(string s,int &n,T A[]){n=0;istringstream sin(s);for(T v;sin>>v;A[n++]=v);}//NOTES:stoa(
template<class T> void atos(int n,T A[],string &s){ostringstream sout;for(int i=0;i<n;i++){if(i>0)sout<<' ';sout<<A[i];}s=sout.str();}//NOTES:atos(
template<class T> void atov(int n,T A[],vector<T> &vi){vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);}//NOTES:atov(
template<class T> void vtoa(vector<T> vi,int &n,T A[]){n=vi.size();for (int i=0;i<n;i++)A[i]=vi[i];}//NOTES:vtoa(
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}//NOTES:vtos(
//Fraction
template<class T> struct Fraction{T a,b;Fraction(T a=0,T b=1);string toString();};//NOTES:Fraction
  template<class T> Fraction<T>::Fraction(T a,T b){T d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
  template<class T> string Fraction<T>::toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
  template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);}
  template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.a,p.b*q.b);}
  template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q){return Fraction<T>(p.a*q.b,p.b*q.a);}
//ENDTEMPLATE_BY_ACRUSH_TOPCODER

const double W=5;
const int maxn=50+5;
const int maxsize=1000000;

int n;
int size;
vector<int> g[maxsize],g2[maxsize];
char s[maxn][10];
double v[maxn],p[maxn];

int sizeq2;
int q2[maxsize];
bool visited[maxsize];
int exp_color,color[maxsize];

int sk[maxsize],sksize,last[maxsize];

void DFS1(int p)
{
	sksize=0;
	sk[sksize++]=p;
	last[p]=SIZE(g[p]);
	visited[p]=true;
	while (sksize>0)
	{
		int p=sk[sksize-1];
		if (last[p]==0)
		{
			q2[sizeq2++]=p;
			sksize--;
		}
		else
		{
			last[p]--;
			int other=g[p][last[p]];
			if (!visited[other])
			{
				visited[other]=true;
				last[other]=SIZE(g[other]);
				sk[sksize++]=other;
			}
		}
	}
}
void DFS2(int p)
{
	sksize=0;
	sk[sksize++]=p;
	last[p]=SIZE(g2[p]);
	color[p]=exp_color;
	while (sksize>0)
	{
		int p=sk[sksize-1];
		if (last[p]==0)
			sksize--;
		else
		{
			last[p]--;
			int other=g2[p][last[p]];
			if (color[other]<0)
			{
				color[other]=exp_color;
				last[other]=SIZE(g2[other]);
				sk[sksize++]=other;
			}
		}
	}
}

int idx(int a,int b,int c)
{
	return a*n*2+b*2+c;
}
void add(int a,int b)
{
	//printf("%2d %d %d   %2d %d %d\n",a/n/2,a/2%n,a%2,b/n/2,b/2%n,b%2);
	g[a].push_back(b);
}
double solve()
{
	vector<double> pts;
	pts.push_back(0);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) if (i!=j && fabs(v[i]-v[j])>eps)
		for (int d=-1;d<=1;d+=2)
		{
			double x=(p[j]-p[i]+W*d)/(v[i]-v[j]);
			if (x>=0) pts.push_back(x);
		}
	sort(pts.begin(),pts.end());
	int pts_cnt=0;
	for (int i=0;i<SIZE(pts);i++) if (i==0 || pts[i]-pts[i-1]>eps) pts[pts_cnt++]=pts[i];
	pts.resize(pts_cnt);
	int H=0,T=SIZE(pts);
	for (;H+1<T;)
	{
		int M=H+(T-H)/2;
		size=(M+M)*n*2;
		for (int i=0;i<size;i++) g[i].clear();
		for (int k=0;k<M;k++)
		{
			if (k+1>=SIZE(pts)) continue;
			double x[60];
			double t=(pts[k]+pts[k+1])/2;
			for (int i=0;i<n;i++) x[i]=p[i]+v[i]*t;
			for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) if (fabs(x[i]-x[j])<W-eps) 
			{
				add(idx(k+k+1,i,0),idx(k+k+1,j,1));
				add(idx(k+k+1,i,1),idx(k+k+1,j,0));
				add(idx(k+k+1,j,0),idx(k+k+1,i,1));
				add(idx(k+k+1,j,1),idx(k+k+1,i,0));
			}
		}
		for (int k=0;k<M;k++)
		{
			if (k>0)
				for (int i=0;i<n;i++)
				{
					add(idx(k+k,i,0),idx(k+k-1,i,0));
					add(idx(k+k,i,1),idx(k+k-1,i,1));
				}
			if (k+1<M)
				for (int i=0;i<n;i++)
				{
					add(idx(k+k+1,i,0),idx(k+k+2,i,0));
					add(idx(k+k+1,i,1),idx(k+k+2,i,1));
				}
			double x[60];
			double t=pts[k];
			for (int i=0;i<n;i++) x[i]=p[i]+v[i]*t;
			for (int i=0;i<n;i++)
			{
				bool ok=true;
				for (int j=0;j<n;j++) if (i!=j && fabs(x[i]-x[j])<W-eps) { ok=false; break; }
				if (!ok) 
				{
					add(idx(k+k,i,0),idx(k+k+1,i,0));
					add(idx(k+k,i,1),idx(k+k+1,i,1));
					add(idx(k+k+1,i,0),idx(k+k,i,0));
					add(idx(k+k+1,i,1),idx(k+k,i,1));
				}
			}
		}
		for (int i=0;i<n;i++) 
			if (s[i][0]=='L')
				add(idx(0,i,1),idx(0,i,0));
			else
				add(idx(0,i,0),idx(0,i,1));
		bool valid=true;
		sizeq2=0;
		for (int i=0;i<size;i++) visited[i]=false;
		for (int i=0;i<size;i++) g2[i].clear();
		for (int i=0;i<size;i++) for (int j=0;j<SIZE(g[i]);j++) g2[g[i][j]].push_back(i);
		for (int i=0;i<size;i++) if (!visited[i]) DFS1(i);
		exp_color=0;
		for (int i=0;i<size;i++) color[i]=-1;
		for (int i=sizeq2-1;i>=0;i--)
		{
			int key=q2[i];
			if (color[key]>=0) continue;
			DFS2(key);
			exp_color++;
		}
		for (int i=0;i<size;i+=2) if (color[i]==color[i+1]) valid=false;
		if (valid)
			H=M;
		else
			T=M;
	}
	if (H>=SIZE(pts)-1) return 1e100;
	return pts[H];
}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%s%lf%lf",&s[i],&v[i],&p[i]);
		double ret=solve();
		printf("Case #%d: ",case_id);
		if (ret>1e99)
			printf("Possible\n");
		else
			printf("%.18lf\n",ret);		
	}
	return 0;
}