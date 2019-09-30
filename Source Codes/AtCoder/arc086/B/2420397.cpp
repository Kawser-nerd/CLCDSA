#include <iostream>
#include <vector>

using namespace std;

int N;
int a[50];

int argmax(bool rev) {
    int mx = -1;
    int mxi = 0;
    for (int i = 0; i < N; ++i) {
        int ai = rev ? -a[i] : a[i];
        if (ai > mx) {
            mx = ai;
            mxi = i;
        }
    }
    return mxi;
}

int allsign() {
    int ans = a[0] == 0 ? 0 : a[0] / abs(a[0]);
    for (int i = 1; i < N; ++i) {
        int si = a[i] == 0 ? 0 : a[i] / abs(a[i]);
        if (ans != si) return 2;
    }
    return ans;
}

int main(){
    cin >> N;
    for (int i = 0;i < N; ++i) {
        cin >> a[i];
    }
    int as = allsign();
    if (as == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (as == 2) {
        cout << 2 * N - 2 << endl;
        int maxi = argmax(false);
        int mini = argmax(true);
        int k = 0;
        if (a[maxi] > - a[mini]) {
            as = 1;
            k = maxi;
        } else {
            as = -1;
            k = mini;
        }

        for (int i = 0; i < N; ++i) {
            if (i == k) continue;
            cout << k + 1 << " " << i + 1 << endl;
        }
    } else {
        cout << N - 1 << endl;
    }

    if (as == 1) {
        for (int i = 0; i < N - 1; ++i) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        for (int i = N; i > 1; --i) {
            cout << i << " " << i - 1 << endl;
        }
    }
}