#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<ull> A;
    for (int i = 0; i < N; ++i) {
        ull tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    int ans = 0;
    while (true) {
        for (int i = 0; i < N; ++i) {
            if (A[i] % 2 != 0) {
                cout << ans << endl;
                return 0;
            } else {
                A[i] /= 2;
            }
        }
        ++ans;
    }
    cout << ans << endl;
}