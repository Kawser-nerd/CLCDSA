#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<LL> VI;
typedef pair<LL,LL> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

typedef LL T; const T EPS = 0;
//typedef double T; const T EPS = 1e-9;
typedef pair<T,T> Point;
//class Point:public pair<T,T>{public: LL id;}; 

const LL MAXN = 100000;

int N;                //IN: Liczba punktów
Point Points[MAXN];   //IN: Punkty - psute! (sort)
LL H;                //OUT:Wielkość otoczki
Point hull[MAXN+5];   //OUT:Kolejne punkty w kolejności CCW

LL det(Point a, Point b) {
    return a.st * b.nd - a.nd * b.st;
}

LL det(Point a, Point b, Point c) {
  T A[] = {a.st-b.st,a.nd-b.nd,b.st-c.st,b.nd-c.nd};
  T dt = A[0]*A[3] - A[1]*A[2];  //Dla T=LL -> uwzględnić rozmiar (LL)!

  return dt;
}

inline bool ccw(Point& a, Point& b, Point& c){
  T A[] = {a.st-b.st,a.nd-b.nd,b.st-c.st,b.nd-c.nd};
  T det = A[0]*A[3] - A[1]*A[2];  //Dla T=LL -> uwzględnić rozmiar (LL)!
  T cro = A[0]*A[2] + A[1]*A[3];  //Dla T=LL -> uwzględnić rozmiar (LL)!
  return (det > EPS) || ((det>=-EPS) && (cro < -EPS));
}; //Zamienić na det>=-EPS dla "słabej" wypłuczki (uwaga na wszystkie współliniowe!)

inline void addPoint(LL i){
  while((H > 1) && (!ccw(hull[H-2], hull[H-1], Points[i])))H--;
  hull[H++] = Points[i];  
}
void computeHull(){
  LL d = 0;
  sort(Points, Points+N);
  //N = unique(Points, Points+N)-Points;// Potrzebne TYLKO jeśli N>1 i wszystkie równe
                                        //     (można obsłużyć inaczej)
  H = 0;                                       
  REP(i,N)addPoint(i);
  if(N<2)return;
  FORD(i,N-1,0)addPoint(i);  
  H--;
}

Point operator-(Point a, Point b) {
    return Point(a.st - b.st, a.nd - b.nd);

}

// PRZECINANIE ODCINKOW

// Bartosz Walczak

#define x first
#define y second
typedef LL K;
typedef Point P;
struct segment { Point a, b; }; // odcinek domkniety

// Punkt p lezy na prostej zawierajacej s. Czy lezy na odcinku s?
bool on_segment(const P&p, const segment &s) // (*)
  { return min(s.a.x, s.b.x)<=p.x+EPS && p.x<=max(s.a.x, s.b.x)+EPS &&
           min(s.a.y, s.b.y)<=p.y+EPS && p.y<=max(s.a.y, s.b.y)+EPS; }
// Czy dwa odcinki maja wspolny punkt?
bool intersect(const segment &s1, const segment &s2) {
    K d1 = det(s2.b-s2.a, s1.a-s2.a), d2 = det(s2.b-s2.a, s1.b-s2.a),
      d3 = det(s1.b-s1.a, s2.a-s1.a), d4 = det(s1.b-s1.a, s2.b-s1.a);
    return (d1>EPS && d2<-EPS || d1<-EPS && d2>EPS) &&
           (d3>EPS && d4<-EPS || d3<-EPS && d4>EPS) ||
           abs(d1)<=EPS && on_segment(s1.a, s2) ||
           abs(d2)<=EPS && on_segment(s1.b, s2) ||
           abs(d3)<=EPS && on_segment(s2.a, s1) ||
           abs(d4)<=EPS && on_segment(s2.b, s1);
}


LL area(Point* T, LL N) {
    LL r = 0;
    REP(i,N) r += det(T[i], Point(0,0), T[(i+1)%N]);
    return abs(r);
}

Point pts[MAXN];
Point pts2[MAXN];

LL perm[MAXN];
void scase() {
    scanf("%d",&N);
    REP(i,N) scanf("%lld%lld",&pts[i].st, &pts[i].nd);
    REP(i,N) Points[i] = pts[i];
    computeHull();
    
    LL A = area(hull, H);
    REP(i,N) perm[i] = i;
    
    while(true) {
        random_shuffle(perm, perm + N);  
        
        segment s1, s2;
        
        bool good = false;
        while(!good) {
            good = true;
            REP(i,N)REP(j,i) {
                if (abs((i-j)%N) == 1 || abs((i-j)%N) == N - 1) continue;
                
                s1.a = pts[perm[i]];
                s1.b = pts[perm[(i+1)%N]];
                s2.a = pts[perm[j]];
                s2.b = pts[perm[j+1]];
                if (intersect(s1,s2)) {
                    good = false;
                    reverse(perm + j + 1, perm + i + 1);
                }
            }        
        }
        
        REP(i,N)REP(j,i) {
            if (abs((i-j)%N) == 1 || abs((i-j)%N) == N - 1) continue;
            
            s1.a = pts[perm[i]];
            s1.b = pts[perm[(i+1)%N]];
            s2.a = pts[perm[j]];
            s2.b = pts[perm[j+1]];
            if (intersect(s1,s2)) {
                goto fail;        
            }
        }
        
        REP(i,N-1) REP(j,N) {
            if (j == i || j == i+1) continue;
            if (det(pts[perm[i]],pts[perm[i+1]],pts[perm[j]])) continue;
            segment s;
            s.a = pts[perm[i]];
            s.b = pts[perm[i+1]];
            if (on_segment(pts[perm[j]], s)) goto fail;        
        }
        
        REP(i,N) pts2[i] = pts[perm[i]];
        if (area(pts2,N) * 2 <= A) goto fail;
        
        REP(i,N) printf("%d ",perm[i]);
        printf("\n");
        return;
        fail:;
    };
    


}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
