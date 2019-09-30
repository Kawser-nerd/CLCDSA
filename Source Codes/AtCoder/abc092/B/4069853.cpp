#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

int main() {
    int N, D, X;
    cin >> N;
    cin >> D >> X;

    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    int ans = X;
    for (int i = 0; i < D; ++i) {
        for (int a : A) {
            if (i % a == 0) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
}