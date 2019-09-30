#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
int x[100000];
int main(){
    cin >> n;

    int mx;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        if (mx < x[i]) mx = x[i];
    }

    sort(x, x + n);
    int ans1 = x[n - 1];
    double mid = ans1 / 2.;
    double mnd = ans1;
    int ans2 = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (abs(x[i] - mid) < mnd) {
            mnd = abs(x[i] - mid);
            ans2 = x[i];
        }
    }

    cout << ans1 << " " << ans2 << endl;
}