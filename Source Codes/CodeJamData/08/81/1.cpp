#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <string>
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

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

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
#define PB push_back
#define M_PI       3.14159265358979323846
#define eps 1.0e-11

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int bitcnt(T n){ int res=0; for (; n!=0; n&=n-1) res++; return res; }

template<class T> inline T checkMod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(

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

class Point
{
public:
	double x,y;
	Point() {};
	Point(double _x,double _y) : x(_x),y(_y) {}
	void Read()
	{
	//	scanf("%d%d",&x,&y);
	}
	void Swap()
	{
		swap(x,y);
	}
};

Point operator+ (const Point &a, const Point &b)
{
	return Point(a.x+b.x,a.y+b.y);
}

Point operator- (const Point &a, const Point &b)
{
	return Point(a.x-b.x,a.y-b.y);
}

Point operator* (const int a, const Point &b)
{
	return Point(a*b.x,a*b.y);
}

double operator* (const Point &a, const Point &b)
{
	return a.x*b.x+a.y*b.y;
}

double operator^ (const Point &a, const Point &b)
{
	return a.x*b.y-a.y*b.x;
}

bool operator== (const Point &a, const Point &b)
{
	return a.x==b.x && a.y==b.y;
}

bool operator< (const Point &a, const Point &b)
{
	return a.x<b.x || a.x==b.x && a.y<b.y;
}

bool operator!= (const Point &a, const Point &b)
{
	return a.x!=b.x || a.y!=b.y;
}

#define EPS 1.0e-9

bool checkinside(Point* a, Point p)
{
	REP(i,3)
	{
		Point q = a[i],  q2 = a[(i+1)%3],  q3 = a[(i+2)%3];
		if (((q2-q)^(p-q))*((p-q)^(q3-q)) < -EPS)
			return false;
	}
	return true;
}

template <int SZ>
class LinearEq
{
public:
	double a[SZ][SZ],b[SZ],x[SZ];
	int n,m;
	void make(int n) {this->n = n; m = 0; memset(a,0,sizeof a); memset(b,0,sizeof b);}
	bool solve()
	{
		if (n != m) n/=0;
		static int perm[SZ];
		static bool u[SZ];
		memset(u,0,sizeof u);
		for (int i = 0; i < n-1; i++)
		{
			static int col;
			for (col = 0; col < n && (fabs(a[i][col]) < EPS || u[col]); col++);
            if (col >= n) return false;
			perm[i] = col;
			u[col] = true;
			for (int j = i+1; j < n; j++)
			{
				double k = a[j][col]/a[i][col];
				a[j][col] = 0;
				for (int l = 0; l < n; l++)
					if (!u[l])
						a[j][l] -= a[i][l]*k;
				b[j] -= b[i]*k;
			}
		}
		for (int i = 0; i < n; i++)
			if (!u[i])
			{
				x[i] = b[n-1]/a[n-1][i];
				break;
			}
		for (int i = n-2; i >= 0; i--)
		{
			static double sum;
			sum = b[i];
			for (int j = 0; j < n; j++)
				if (!u[j])
					sum -= x[j]*a[i][j];
			x[perm[i]] = sum / a[i][perm[i]];
			u[perm[i]] = false;
		}
        return true;
	}
	inline double& operator [](int p)
	{
		return x[p];
	}
};


#define NAME "A-large"

Point a[3],b[3];
Point offset;
LinearEq<4> A;
LinearEq<4> AA;

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"Test #%d\n",tst+1);

		REP(i,3)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		REP(i,3)
			scanf("%lf%lf",&b[i].x,&b[i].y);
		Point base = a[0];
		REP(i,3)
		{
			a[i]=a[i]-base;
			b[i]=b[i]-base;
		}
		offset = b[0];
		Point d1 = a[1]-a[0];
		Point d2 = a[2]-a[0];
		Point dd1 = b[1]-b[0];
		Point dd2 = b[2]-b[0];
		A.make(4);		
		double qq[4] = {dd1.x,dd2.x,dd1.y,dd2.y};
		REP(i,4)
		{
			double k1,k2;
			if ((i%2) == 0)
			{
				k1=d1.x;
				k2=d1.y;
			}
			else
			{
				k1=d2.x;
				k2=d2.y;
			}
			
			if (i<=1)
			{
				A.a[A.m][0]=k1;
				A.a[A.m][1]=k2;
			}
			else
			{
				A.a[A.m][2]=k1;
				A.a[A.m][3]=k2;
			}
			A.b[A.m]=qq[i];
			A.m++;
		}
		bool bad=false;
		Point res;
		if (A.solve())
		{
			AA.make(2);
			AA.m=2;
			AA.a[0][0]=A[0]-1;
			AA.a[0][1]=A[1];
			AA.a[1][0]=A[2];
			AA.a[1][1]=A[3]-1;
			AA.b[0]=-offset.x;
			AA.b[1]=-offset.y;
			if (AA.solve())
			{
				res=Point(AA[0],AA[1])+base;
				bad = !checkinside(a, Point(AA[0],AA[1])) || !checkinside(a, Point(AA[0],AA[1]));
			}
			else
				bad=true;
		}
		else
			bad=true;
			

		printf("Case #%d: ",tst+1);
		if (bad) printf("No Solution\n");
		else printf("%.8lf %.8lf\n",res.x,res.y);
	}
	return 0;
}
