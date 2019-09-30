#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int x = n;
    for (int i = 1; i <= n/2 + 1; ++i) {
        int j = n / i;
        x = min(x, (abs(i-j) + n-(i*j)) );
    }
    cout << x << endl;
    return 0;
}