// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

typedef complex<double> point;

double square_size(const point &A) { return real(A) * real(A) + imag(A) * imag(A); }
double dot_product(const point &A, const point &B) { return real(A)*real(B) + imag(A)*imag(B); }
double cross_product(const point &A, const point &B) { return real(A) * imag(B) - real(B) * imag(A); }

#define EPSILON (1e-7)
bool is_negative(double x) { return x < -EPSILON; } 
bool is_zero(double x) { return abs(x) <= EPSILON; } 
bool is_positive(double x) { return x > EPSILON; }
bool are_equal(const point &A, const point &B) { return is_zero(real(B)-real(A)) && is_zero(imag(B)-imag(A)); }
int signum(const double &A) { if (is_zero(A)) return 0; if (is_negative(A)) return -1; return 1; }

bool colinear(const point &A, const point &B, const point &C) { return is_zero( cross_product( B-A, C-A )); }
bool colinear(const point &B, const point &C) { return is_zero( cross_product( B, C )); }

bool clockwise(const point &A, const point &B, const point &C) { return is_negative( cross_product( B-A, C-A )); }
bool clockwise(const point &B, const point &C) { return is_negative( cross_product( B, C )); }

bool counterclockwise(const point &A, const point &B, const point &C) { return is_positive( cross_product( B-A, C-A )); }
bool counterclockwise(const point &B, const point &C) { return is_positive( cross_product( B, C )); }

bool compare_arg(const point &A, const point &B) { 
    // [0,0] ide uplne na zaciatok
    if (are_equal(B,point(0,0))) return 0;
    if (are_equal(A,point(0,0))) return 1;
    // chceme poradie: pod osou x zlava doprava, kladna poloos, nad osou sprava dolava, zaporna poloos
    int sgnA = signum(imag(A));
    int sgnB = signum(imag(B));
    if (sgnA == 0) if (signum(real(A))<0) sgnA = 2;
    if (sgnB == 0) if (signum(real(B))<0) sgnB = 2;
    if (sgnA != sgnB) return (sgnA < sgnB);
    // v ramci polroviny sortime podla clockwise
    if (counterclockwise(A,B)) return 1;
    if (clockwise(A,B)) return 0;
    // a ak sa este nerozhodlo, podla vzdialenosti, blizsie skor
    return (square_size(A) < square_size(B));
}

bool compare_YX(const point &A, const point &B) { if (!is_zero(imag(A)-imag(B))) return (is_negative(imag(A)-imag(B))); return (is_negative(real(A)-real(B))); }

vector<point> convex_hull( vector<point> V ) { 
    // handle boundary cases
    if (V.size() == 2) if (V[0]==V[1]) V.pop_back();
    if (V.size() <= 2) return V;
    sort(V.begin(), V.end(), compare_YX);
    point offset = V[0];
    for (unsigned int i=0; i<V.size(); i++) V[i] -= offset;
    sort(V.begin()+1, V.end(), compare_arg );
    int count = 2;
    vector<int> hull(V.size()+2);
    for (unsigned int i=0; i<2; i++) hull[i]=i;
    for (unsigned int i=2; i<V.size(); i++) {
        while (count>=2 && !counterclockwise( V[hull[count-2]], V[hull[count-1]], V[i] ) ) count--;
        hull[count++]=i;
    }
    vector< point > res;
    for (int i=0; i<count; i++) res.push_back( V[hull[i]] + offset );
    if (res.size()==2) if (are_equal(res[0],res[1])) res.pop_back();
    return res;
}

point rotate_point(const point &bod, const point &stred, double uhol) { 
    point mul(cos(uhol),sin(uhol)); return ((bod-stred)*mul)+stred; 
}

int main() {
    int T;
    cin >> T;
    FOR(t,1,T) {
        int N; cin >> N;
        int M; cin >> M;
        vector<point> STARS;
        REP(n,N) { double x,y; cin >> x >> y; STARS.push_back(point(x,y)); }
        vector<point> LOC(1,point(0,0));
        while (M--) {
            vector<point> nLOC(LOC.begin(),LOC.end());
            for (auto P : LOC) {
                for (auto S : STARS) {
                    point Q = rotate_point(P,S,-0.5*M_PI);
                    nLOC.push_back(Q);
                }
            }
            if (SIZE(nLOC) > 5000) nLOC = convex_hull(nLOC);
            LOC = nLOC;
        }
        double best = 0.;
        for (auto P : LOC) best = max(best,sqrt(square_size(P)));
        printf("Case #%d: %.10f\n",t,best);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
