#include<iostream>
#include <string>
using namespace std;

int main() {
    int n, s, t, w;
    int a[1010];
    cin >> n >> s >> t;
    cin >> w;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    a[0] = 0;
    for (int i = 0; i < n; ++i){
        w += a[i];
        if (w >= s && w <= t) {
            res++;
        }
    }
    cout << res << endl;
}