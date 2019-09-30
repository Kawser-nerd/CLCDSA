#include <iostream>

using namespace std;

typedef long long ll;

int t;
ll n;
int c[10];

void solve(int x) {
    cin >> n;
    cout << "Case #" << x << ": ";
    if (n == 0) {
        cout << "INSOMNIA\n";
        return;
    }
    for (int i = 0; i <= 9; i++) c[i] = 0;
    int k = 0;
    for (int i = 1; ; i++) {
        ll u = n*i;
        while (u) {
            if (c[u%10] == 0) {
                c[u%10] = 1;
                k++;
            }
            u /= 10;
        }
        if (k == 10) {
            cout << n*i << "\n";
            return;
        }
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
