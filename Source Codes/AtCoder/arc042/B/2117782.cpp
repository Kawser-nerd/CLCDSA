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

signed main(){
    double x, y;
    int n;
    cin >> x >> y >> n;

    vector<double> px(n), py(n);
    for(int i = 0; i < n; i++){
        cin >> px[i] >> py[i];
    }

    double d = inf;
    for(int i = 0; i < n; i++){
        double a = (py[(i+1)%n]-py[i]) / (px[(i+1)%n]-px[i]);
        double b = py[i] - a * px[i];
        double tmp = abs(a * x - y + b) / sqrt(a*a+1);
        if(tmp < d){
            d = tmp;
        }
    }
    cout << fixed << setprecision(6) << d << endl;

    return 0;
}