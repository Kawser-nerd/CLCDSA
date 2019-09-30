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
    ull N;
    cin >> N;

    ull ans = 1;
    for (ull i = 1; i * i <= N; ++i) {
        ans = i * i;
    }
    cout << ans << endl;
}