#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> t;
vector<int> x;
vector<int> y;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ti, xi, yi;
        cin >> ti >> xi >> yi;
        t.push_back(ti);
        x.push_back(xi);
        y.push_back(yi);
    }

    int ct = 0, cx = 0, cy = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int dist = abs(x[i] - cx) + abs(y[i] - cy);
        int dt = t[i] - ct;
        //cout <<dt << ", " << dist << endl;
        if (dist <= dt && dt % 2 == dist % 2) {
            ct = t[i];
            cx = x[i];
            cy = y[i];
            //cout << "ok" << endl;
        } else {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}