#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define EPS 1e-8
using namespace std;

struct vect{
	int x, y;
	vect(){}
	vect(int x, int y) : x(x), y(y){}
	vect operator + (vect const &T) const{return vect(x+T.x, y+T.y);}
	vect operator - (vect const &T) const{return vect(x-T.x, y-T.y);}
	vect operator * (int const &t) const{return vect(x*t, y*t);}
	int operator % (vect const &T) const{return x*T.x + y*T.y;}
	int operator ^ (vect const &T) const{return x*T.y - y*T.x;}
	double len(){return sqrt(x*1.*x + y*1.*y);}
};

int n, res[15], per[15];
vect p[15];

int NB(int a, int b){
	if (b < 0) b = -b, a = -a;
	return a <= 0 || a >= b;
}


int onSeg(vect p, vect L1, vect L2){
	if (fabs((p - L1).len()) <= EPS) return 0;
	if (fabs((p - L2).len()) <= EPS) return 0;
	return fabs((p-L1).len() + (p-L2).len() - (L2-L1).len()) <= EPS;
}

int Touch(vect p, vect L1, vect L2){
	return fabs((p-L1).len() + (p-L2).len() - (L2-L1).len()) <= EPS;
}


int Cross(vect L1, vect L2, vect S1, vect S2){
	int w, u, v;
	w = (L2-L1)^(S2-S1);
	if (w == 0){
		if (onSeg(L1, S1, S2)) return 1;
		if (onSeg(L2, S1, S2)) return 1;
		if (onSeg(S1, L1, L2)) return 1;
		if (onSeg(S2, L1, L2)) return 1;
		return 0;
	}
	u = ((S1-L1)^(S2-S1));
	v = ((L1-S1)^(L2-L1));
	return 1 - (NB(u, w) || NB(v, -w));
}
void solve(int tc){
	printf("Case #%d:", tc);
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d%d", &p[i].x, &p[i].y), per[i] = i;
	int mx = 0;
	do{
		int A = 0, ok = 1;
		per[n] = per[0];
		FOR(i,0,n) A += p[per[i]] ^ p[per[i+1]];
		if (A <= mx) ok = 0;
		
		for (int i=0; i<n && ok; i++)
		for (int j=0; j<i && ok; j++){
			if (Cross(p[per[i]], p[per[i+1]], p[per[j]], p[per[j+1]])) ok = 0;
		}
		for (int i=0; i<n && ok; i++)
		for (int k=0; k<n && ok; k++) if (k != per[i] && k != per[i+1]){
			if (Touch(p[k], p[per[i]], p[per[i+1]])) ok = 0;
		}
		
		
		if (ok){
			mx = A;
			FOR(i,0,n) res[i] = per[i];
		}
	}   while (next_permutation(per, per + n));
	
	int ok = 1;
	res[n] = res[0];
	FOR(i,0,n) FOR(j,0,i) if (Cross(p[res[i]], p[res[i+1]], p[res[j]], p[res[j+1]])) {
		printf("Cross %d %d %d %d (%d,%d)\n", res[i], res[i+1], res[j], res[j+1], i, j);
		ok = 0;
	}
//	printf("[%d]\n", ok);
	
	FOR(i,0,n) printf(" %d", res[i]);
	puts("");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
