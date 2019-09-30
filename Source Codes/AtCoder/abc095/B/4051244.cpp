#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int ans = 0;
    int cost = 9999;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        X -= tmp;
        ++ans;
        cost = min(cost, tmp);
    }
    while (X - cost >= 0) {
        X -= cost;
        ++ans;
    }
    cout << ans << endl;
}