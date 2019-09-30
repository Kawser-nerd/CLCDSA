#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    string s;
    cin >> s;

    int ans = 1000;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;

        int mx = 0;
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == c) {
                mx = max(mx, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        mx = max(mx, cnt);

        ans = min(ans, mx);
    }

    cout << ans << "\n";
    return 0;
}