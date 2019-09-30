#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    int N;
    cin >> N;
    ll a = 0;
    int v[100001] = {};
    for(int i = 0; i < N; i++) {
        cin >> a;
        v[a + 1]++;
        v[a]++;
        v[a - 1]++;
    }

    int max = 1;
    for (int i = 0; i < 100001; i++) {
        if(v[i] > max) {
            max = v[i];
        }
    }

    cout << max << endl;

    return 0;
}