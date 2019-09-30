#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;

int N, Q;
double X[100], R[100], H[100];

double query(int i, double x1, double x2){

    double x = X[i];
    double r = R[i];
    double h = H[i];
    double pi = M_PI;

    double base = 1.0 / 3.0 * pi * r * r * h;
    // fprintf(stderr, "i:%d x1:%.0f x2:%.0f x:%.0f r:%.2f h:%.2f\n", i, x1, x2, x, r, h);
    if(x + h < x1) return 0;
    if((x < x1) && (x + h < x2)) {
        double r1 = x + h - x1;
        double r2 = x1 - x;
        return base * pow(r1 / h, 3.0);
    }
    if((x < x1) && (x + h >= x2)) {
        double r1 = x + h - x2;
        double r2 = x2 - x1;
        double r3 = x1 - x;
        return base * (pow((r1 + r2)/ h, 3.0) - pow(r1/ h, 3.0));
    }
    if((x < x2) && (x + h < x2)){
        return base;
    }
    if((x < x2) && (x + h >= x2)){
        double r1 = x + h - x2;
        double r2 = x2 - x;
        return base * (1.0 - pow(r1/h, 3.0));
    }

    // x >= x2
    return 0.0;

}

int main() {

    cin >> N >> Q;
    rep(i, N){
        cin >> X[i] >> R[i] >> H[i];
    }

    rep(i, Q){
        double ret = 0.0;
        double x1, x2;
        cin >> x1 >> x2;

        rep(j, N){
            double q = query(j, x1, x2);
            ret += q;
        }
        printf("%.6f\n", ret);

    }
}