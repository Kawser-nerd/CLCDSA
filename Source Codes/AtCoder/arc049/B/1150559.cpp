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
int N;
double X[MAX_N], Y[MAX_N], C[MAX_N];

double DIST = 1000000.0;

bool query(double t){
    double L = -DIST;
    double R = DIST;
    double U = -DIST;
    double D = DIST;
    rep(i, N){
        L = max(L, X[i] - t / C[i]);
        R = min(R, X[i] + t / C[i]);
        U = max(U, Y[i] - t / C[i]);
        D = min(D, Y[i] + t / C[i]);
    }

    // fprintf(stderr, "%.4f %.4f %.4f %.4f \n", t, L, R, U, D);
    return (L <= R && U <= D);
}

double binarySearch(double left, double right){
    double EPS = 1e-6;
    while (left < right){
        double mid = (left + right) / 2;
        bool b = query(mid);
        // fprintf(stderr, "%.4f %.4f %d \n", left, right, b);
        if (b){
            right = mid;
        }
        else{
            left = mid;
        }
        if(right - left < EPS) return mid;
    }
    return -1;
}

int main() {
    cin >> N;
    rep(i, N){
        cin >> X[i] >> Y[i] >> C[i];
    }
    printf("%.6f\n", binarySearch(0.0, 1000.0 * DIST));
}