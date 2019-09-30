#include <iostream>
#include <map>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


const int INF = 1000000000 + 7;


int main() {
    int n; string s;
    cin >> n >> s;

    map<char, int> counter;
    rep (i, n) {
        if (counter.find(s[i]) == counter.end()) counter[s[i]] = 1;
        else counter[s[i]]++;
    }

    long long ans = 1;
    for (auto elem : counter) {
        ans *= elem.second+1;
        ans %= INF;
    }

    cout << ans-1 << endl;
    return 0;
}