#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <random>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;
const double TRIAL = 30e4;

signed main(){
    int n;
    cin >> n;

    vector<double> x(n), y(n);
    rep(i, n){
        cin >> x[i] >> y[i];
    }

    vector<int> p(n);
    rep(i, TRIAL){
        double rx = sin(2*M_PI*i/TRIAL);
        double ry = cos(2*M_PI*i/TRIAL);

        double d = rx*x[0]+ry*y[0];
        int np = 0;
        for(int j = 1; j < n; j++){
            double dd = rx*x[j]+ry*y[j];
            if(dd > d){
                d = dd;
                np = j;
            }
        }
        p[np]++;
    }

    rep(i, n){
        cout << fixed << setprecision(6) << (double)p[i] / (double)TRIAL << endl;
    }

    return 0;
}