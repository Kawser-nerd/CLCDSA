#include <bits/stdc++.h>

using namespace std;

double calc(double km, double s) {
    return km/s;
}

double speed(double n, vector<pair<double,double> > vec) {
    double res = calc(n-vec[0].first,vec[0].second);
    for(int i=1;i<vec.size();i++) {
        res = max(res,calc(n-vec[i].first,vec[i].second));
    }
    res = n/res;
    return res;
}

int main() {
    int casos;
    cin >> casos;
    for(int casito = 1 ; casito <= casos; casito++) {
        int n,d;
        cin >> n >> d;
        vector<pair<double,double> > vec(d);
        for(int i=0;i<d;i++) {
            cin >> vec[i].first >> vec[i].second;
        }
        printf("Case #%d: %.6f\n",casito,speed(n,vec));
    }
}