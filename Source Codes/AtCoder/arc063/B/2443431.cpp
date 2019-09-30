#include <iostream>
#include <vector>

using namespace std;

int N, T;
int a[100000];
int mxben[100000];

int main(){
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int mx = -2000000000;
    int mxmxben = -2000000000;
    for (int i = N - 1; i >= 0; --i) {
        cin >> a[i];
        mx = max(a[i], mx);
        mxben[i] = mx - a[i];
        mxmxben = max(mxben[i], mxmxben);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (mxben[i] == mxmxben) ans++;
    }
    cout << ans << endl;
}