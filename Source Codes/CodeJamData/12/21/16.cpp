#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <numeric>
using namespace std;

int main(void) {
    int testCount;
    cin >> testCount;
    cout.setf(std::ios::fixed);
    cout << setprecision(9);
    for (int testNo = 1; testNo <= testCount; ++testNo) {
        int n;
        cin >> n;
        vector<double> pointValue(n);
        for (int i = 0; i < n; i++) {
            cin >> pointValue[i];
        }
        double sum = accumulate(pointValue.begin(), pointValue.end(), 0.0);
        transform(pointValue.begin(), pointValue.end(), pointValue.begin(), [=](double x) -> double { return x / sum; });
        cout << "Case #" << testNo << ":";
        for (int i = 0; i < n; i++) {
            double l = 0, r = 1.0;
            while (r - l > 1e-9) {
                double m = (l + r) / 2.0;
                double tot = m;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    tot += max(0.0, m + pointValue[i] - pointValue[j]);
                }
                if (tot > 1.0) {
                    r = m;
                } else
                    l = m;
            }
            cout << " " << 100*l;
        }
        cout << endl;
    }
    return 0;
}