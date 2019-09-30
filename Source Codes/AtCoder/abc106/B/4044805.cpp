#include <iostream>
#include <set>

using namespace std;

int table[201];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 200; ++i) {
        for (int j = i; j <= 200; j += i) {
            table[j] += 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i += 2) {
        if (table[i] == 8) {
            ans += 1;
        }
    }
    cout << ans << endl;
}