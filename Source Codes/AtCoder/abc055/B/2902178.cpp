#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    long long p = 1;
    long long ans;

    for (int i = 1; i <= n; i++) {
        p *= i;
        p = p % 1000000007;
    }

    cout << p << endl;

    return 0;
}