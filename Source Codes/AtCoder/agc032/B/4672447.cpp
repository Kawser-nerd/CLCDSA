#define P(x) cout << #x " = " << x << endl
#define PP(x, y) cout << "(" #x ", " #y ") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "(" #x ", " #y ", " #z ") = (" << x << ", " << y << ", " << z << ")" << endl

#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>

using namespace std;
int n;

int main()
{
    cin >> n;
    cout << n * (n - 1) / 2 - n / 2 << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (i + j == n / 2 * 2 + 1) continue;
            cout << i << " " << j << endl;
        }
    }
}