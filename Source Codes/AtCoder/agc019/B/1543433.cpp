#include <iostream>
#include <array>
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
using ll = long long;
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    array<int, 26> cnt = {};
    ll result = 1;
    repeat_reverse (i, n) {
        char c = s[i] - 'a';
        cnt[c] += 1;
        result += n - i - cnt[c];
    }
    cout << result << endl;
    return 0;
}