#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 1) c++;
    }

    cout << (c % 2 == 0 ? "YES" : "NO") << "\n";
    return 0;
}