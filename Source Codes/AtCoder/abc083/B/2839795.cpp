#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ret = 0;
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        int temp = i;
        while(temp) {
            ans += temp % 10;
            temp /= 10;
        }

        if (ans >= a && ans <= b)   ret += i;
    }

    cout << ret << endl;
    return 0;
}