#include <iostream>
#include <vector>

using namespace std;
int dsum(int n) {
    int ans = 0;
    while (n != 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int n;

int main(){
    cin >> n;

    int ans = 1000000;
    for (int a = 1; a <= n - 1; ++a) {
        int b = n - a;
        ans = min(ans, dsum(a) + dsum(b));
    }

    cout << ans << endl;
}