#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = i % 2 == 0 ? 'g' : 'p';
        if (c > s[i]) ans++;
        if (c < s[i]) ans--;
    }

    cout << ans << "\n";
    return 0;
}