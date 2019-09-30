#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>

using namespace std;
int counter = 0;
int gcd(int a, int b) {
    if (b == 0) return a;
    counter++;
    return gcd(b, a%b);
}

int cnt(int a, int b) {
    counter = 0;
    gcd(a, b);
    return counter;
}

pair<int, int> recv(int k) {
    if (k == 1) return make_pair(2, 1);
    pair<int, int> prev = recv(k - 1);
    return make_pair(prev.first + prev.second, prev.first);
}
int k;
int main(){
    cin >> k;
    auto ans = recv(k);
    cout << ans.first << " " << ans.second << endl;
    // cout << cnt(ans.first, ans.second) << endl;
}