#include <iostream>
#include <vector>

using namespace std;

int n;
int x[200000];

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int last = 0;
    bool ng = false;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x[i] == max(last - 1, 0)) {
            //cout << i << "  - " << last <<  endl;
        } else if (x[i] > last - 1) {
            //cout << i << " " << x[i] << " las " << last << endl;
            ans += x[i];
            if (x[i] > i) ng = true;
        } else ng = true;
        last = x[i];
    }

    if (ng) ans = -1;
    cout << ans << endl;
}