
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
template<class T> inline T inverse(T a, T n)
{	T x,y; euclide(a,n,x,y); return ((x%n)+n)%n;}

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
template<class T> inline void powerModMatrix(int n, T _A[MaxMatrixSize][MaxMatrixSize], long long k, T C[MaxMatrixSize][MaxMatrixSize])
{	T A[MaxMatrixSize][MaxMatrixSize];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j];
	identityMatrix(n,C);
	while (k)
		if (k%2)
		{
			k--;
			mulModMatrix(n, MOD, C, C, A);
		}
		else
		{
			k/=2;
			mulModMatrix(n, MOD, A, A, A);
		}
}

template<class T> inline void inverseModMatrix(int n, T m, T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize])
{	T A[MaxMatrixSize][MaxMatrixSize];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) A[i][j]=_A[i][j];
	identityMatrix(n,C);
	REP(i,n)
	{
		T inv = inverse(A[i][i],m);
		REP(j,n) A[i][j]=multiplyMod(A[i][j],inv,m),C[i][j]=multiplyMod(C[i][j],inv,m);
		REP(ii,n) if (i!=ii && A[ii][i]!=0)
		{
			T ratio = A[ii][i];
			REP(j,n) A[ii][j]=(A[ii][j]-multiplyMod(A[i][j],ratio,m)+m)%m;
			REP(j,n) C[ii][j]=(C[ii][j]-multiplyMod(C[i][j],ratio,m)+m)%m;
		}
	}
}
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
  template<class T> bool operator<(Fraction<T> p,Fraction<T> q){return p.a*q.b<q.a*p.b;}
  template<class T> bool operator==(Fraction<T> p,Fraction<T> q){return p.a*q.b==q.a*p.b;}
  template<class T> bool operator!=(Fraction<T> p,Fraction<T> q){return p.a*q.b!=q.a*p.b;}
  template<class T> bool operator<=(Fraction<T> p,Fraction<T> q){return p.a*q.b<=q.a*p.b;}
void PrintVI(const VI &a) { REP(i,SZ(a)) printf(" %d"+(i==0),a[i]); printf("\n"); }
void PrintVISZ(const VI &a) { printf("%d\n",SZ(a)); REP(i,SZ(a)) printf(" %d"+(i==0),a[i]); printf("\n"); }




#define NAME "A-large"

#define N 16
int n,m;
char a[N][N];

typedef VPII State;

State read(char c, char c2=0)
{
	State res;
	res.clear();
	REP(i,n) REP(j,m)
		if (a[i][j]==c || a[i][j]==c2)
			res.push_back(PII(i,j));
	SORT(res);
	return res;
}

void clear()
{
	REP(i,n) REP(j,m)
		if (a[i][j]!='#')
			a[i][j]='.';
}

void write(State s, char c)
{
	REP(i,SZ(s))
		a[s[i].X][s[i].Y] = c;
}

bool normal(State s)
{
	bool used[10];
	CLEAR(used);
	used[0]=true;
	REP(step,SZ(s)) REP(i,SZ(s)) if (!used[i]) REP(j,SZ(s)) if (used[j])
	{
		if (abs(s[i].X-s[j].X)+abs(s[i].Y-s[j].Y)==1)
		{
			used[i]=true;
			break;
		}
	}
	REP(i,SZ(s))
		if (!used[i]) return false;
	return true;
}

queue<pair<State,int> > q;
map<State,int> was;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

inline bool empty(int x, int y)
{
	return (x>=0&&x<n&&y>=0&&y<m && a[x][y]=='.');
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"Test #%d\n",tst+1);
		scanf("%d%d",&n,&m);
		REP(i,n) REP(j,m)
		{
			char c;
			do c = getc(stdin);
			while (c<=' ');
			a[i][j]=c;
		}
		State start = read('o','w');
		State finish = read('x','w');
		clear();
		while (!q.empty()) q.pop();
		q.push(make_pair(start,0));
		was.clear();
		was[start]=0;
		while (!q.empty())
		{
			State st = q.front().first;
			int tmm = q.front().second;
			q.pop();
			bool norm1 = normal(st);
			clear();
			write(st,'x');
			REP(i,SZ(st)) REP(dir,4)
			{
				int x = st[i].X;
				int y = st[i].Y;
				if (empty(x+dx[dir],y+dy[dir])&&empty(x-dx[dir],y-dy[dir]))
				{
					State st2 = st;
					st2[i].X += dx[dir];
					st2[i].Y += dy[dir];
					SORT(st2);
					map<State,int>::iterator it = was.find(st2);
					if (norm1 || normal(st2))
						if (it==was.end())
						{
							was[st2]=tmm+1;
							q.push(make_pair(st2,tmm+1));
						}
				}
			}
		}
		int res;
		map<State,int>::iterator it = was.find(finish);
		if (it==was.end())
			res=-1;
		else
			res=it->second;
		printf("Case #%d: %d\n",tst+1,res);
	}
	return 0;
}