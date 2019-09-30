#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define INF (1<<30)
#define EPS 1e-8
#define LLD long long int
#define PB push_back
#define VI vector<int>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
using namespace std;


struct vect{
	double x, y; 
	vect(){}
	vect(double x, double y) : x(x), y(y){}
	vect operator + (vect const &T) const{return vect(x+T.x, y+T.y);}
	vect operator - (vect const &T) const{return vect(x-T.x, y-T.y);}
	vect operator * (double const &t) const{return vect(x*t, y*t);}
	double operator % (vect const &T) const{return x*T.x + y*T.y;}
	double operator ^ (vect const &T) const{return x*T.y - y*T.x;}
	double len(){return sqrt(x*x + y*y);}
	double len2(){return x*x + y*y;}
	vect rot() const{return vect(-y, x);}
	vect rot(double t) const{return vect(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	bool operator < (vect const &T) const{return x==T.x ? y<T.y : x<T.x;}
	int get(){return scanf("%lf%lf", &x, &y);}
	vect norm(){return *this*(1/len());}
	vect resize(double d){return *this * (d / (*this).len()) ;}
}; 

int n, done;
vect l1, l2, norm, p[1000];
int cnt[2][2];

int onLine(vect p, vect L1, vect L2){
	return fabs((L2-L1)^(p-L1)) <= EPS;
}

int LineIntersection(vect L1, vect L2, vect S1, vect S2, vect &P){
	double w, u, v;
	w = (L2-L1)^(S2-S1);
	u = ((S1-L1)^(S2-S1)) / w; 
	v = ((L1-S1)^(L2-L1)) / -w; 
	P = L1 + ((L2-L1) * u);
}


void doit(vect l1, vect l2, vect s1, vect s2){
	CLR(cnt, 0);
	FOR(i,0,n){
		int c1 = ((l2 - l1) ^ (p[i] - l1)) > 0; 
		int c2 = ((s2 - s1) ^ (p[i] - s1)) > 0;
		++cnt[c1][c2];
	}
	int fail = 0;
	FOR(i,0,2) FOR(j,0,2) if (cnt[i][j] != n / 4) fail = 1;
	if (!fail && !done){
		int online = 0;
		FOR(i,0,n) if (onLine(p[i], l1, l2) || onLine(p[i], s1, s2)) online = 1;
		if (online) return;
		done = 1;
		vect p;
		LineIntersection(l1, l2, s1, s2, p);
		printf("%.9f %.9f %.9f %.9f\n", p.x, p.y, l1.x, l1.y);
	}
}

void doit(vect l1, vect l2){
	vect norm = (l2 - l1).rot();
	vect shift = (l2 - l1).resize(1e-8);
	FOR(i,0,n){
		vect per = p[i] + norm;
		doit(l1, l2, p[i] + shift, per + shift);
		doit(l1, l2, p[i] - shift, per - shift);			
	}

}

void solve(int tc){
	scanf("%d", &n);
	n <<= 2;
	FOR(i,0,n) p[i].get();

	printf("Case #%d: ", tc);
	done = 0;
	FOR(i,0,n) FOR(j,0,i){
		l1 = p[i];
		l2 = p[j];
		norm = (l2 - l1);
		norm = norm.rot();
		norm = norm.resize(1e-8);
		doit(l1 - norm, l2 - norm);
		doit(l1 + norm, l2 + norm);
	}
	if (!done){
		FOR(i,0,n) printf("%f %f\n", p[i].x, p[i].y);
		puts("IMPOSSIBLE");
	}

}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
