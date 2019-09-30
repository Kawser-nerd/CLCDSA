#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long func(unsigned long long r, unsigned long long cnt) {
    return (2 * r + 1) * cnt + cnt * (cnt - 1) * 2;
}

int main(void) {
    int T;
    cin >> T;
    for (int testNo = 1; testNo <= T; ++testNo) {
        unsigned long long r, t;
        cin >> r >> t;
        //++r;
        unsigned long long left = 0, right = min(t / (2*r + 1), (unsigned long long)1e9) + 1;
        while (right - left != 1) {
            unsigned long long mid = (left + right) / 2;
            unsigned long long val = func(r, mid);
            if (val > t) {
                right = mid;
            } else
                left = mid;
        }
        if (func(r, left) > t || func(r, right) <= t) {
            cerr << "SHIT" << endl;
        }
        cout << "Case #" << testNo << ": " << left << endl;
    }
}

