#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;

bool judge(const vector<int>& x, const vector<int>& y, const vector<int>& c, const double& m){
    double l = x[0] - m / c[0];
    double r = x[0] + m / c[0];
    double u = y[0] - m / c[0];
    double d = y[0] + m / c[0];
    for(int i = 1; i < x.size(); i++){
        if(l > x[i] + m / c[i] || r < x[i] - m / c[i] || u > y[i] + m / c[i] || d < y[i] - m / c[i]){
            return false;
        }
        if(x[i] - m / c[i] > l){
            l = x[i] - m / c[i];
        }
        if(x[i] + m / c[i] < r){
            r = x[i] + m / c[i];
        }
        if(y[i] - m / c[i] > u){
            u = y[i] - m / c[i];
        }
        if(y[i] + m / c[i] < d){
            d = y[i] + m / c[i];
        }
    }

    return true;
}

signed main(){
    int n;
    cin >> n;

    vector<int> x(n), y(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> c[i];
    }

    double l = -1;
    double r = 1e8;
    for(int i = 0; i < 100; i++){
        double m = (l + r) / 2;
        if(judge(x, y, c, m)){
            r = m;
        }else{
            l = m;
        }
    }

    cout << fixed << setprecision(5) << r << endl;

    return 0;
}