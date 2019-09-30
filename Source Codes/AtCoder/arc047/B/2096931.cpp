#include <cmath>
#include <complex>
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

P decode(int p, int q){
    int x = (p + q) / 2;
    int y = p - x;
    return make_pair(x, y);
}

bool check(const vector<int>& x, const vector<int>& y, int p, int q){
    int m = abs(x[0] - p) + abs(y[0] - q);
    for(int i = 1; i < (int)x.size(); i++){
        if(m != abs(x[i] - p) + abs(y[i] - q)){
            return false;
        }
    }
    return true;
}

signed main(){
    int n;
    cin >> n;

    vector<int> x(n), y(n), p(n), q(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        p[i] = x[i] + y[i];
        q[i] = x[i] - y[i];
    }

    int pMax = *max_element(p.begin(), p.end());
    int pMin = *min_element(p.begin(), p.end());
    int qMax = *max_element(q.begin(), q.end());
    int qMin = *min_element(q.begin(), q.end());

    if(pMax - pMin == qMax - qMin){
        int e = pMax - pMin;
        int xx = pMax - e / 2;
        int yy = qMax - e / 2;
        P ans = decode(xx, yy);
        cout << ans.first << " " << ans.second << endl;
    }

    if(pMax - pMin > qMax - qMin){
        int e = pMax - pMin;
        int xx = pMax - e / 2;
        for(int i = qMax - e / 2; i <= qMin + e / 2; i++){
            P ans = decode(xx, i);
            if(check(x, y, ans.first, ans.second)){
                cout << ans.first << " " << ans.second << endl;
                return 0;
            }
        }
    }

    if(pMax - pMin < qMax - qMin){
        int e = qMax - qMin;
        int yy = qMax - e / 2;
        for(int i = pMax - e / 2; i <= pMin + e / 2; i++){
            P ans = decode(i, yy);
            if(check(x, y, ans.first, ans.second)){
                cout << ans.first << " " << ans.second << endl;
                return 0;
            }
        }
    }

    return 0;
}