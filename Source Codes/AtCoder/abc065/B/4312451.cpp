#include <iostream>
#include <vector>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int n;


int solve(vector<int> a) {
    int ptr = 0;
    int cnt = 0;
    rep (i, n) {
        ptr = a[ptr]; cnt++;
        if (ptr == 1) return cnt;
    }
    return -1;
}


int main() {
    cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    rep (i, n) --a[i];
    cout << solve(a) << endl;
    return 0;
}