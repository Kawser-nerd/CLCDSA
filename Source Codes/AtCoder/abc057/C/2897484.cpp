#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n; cin >> n;
    int a = 0, b = 0;

    for (int i = sqrt(n); i >= 1; i--) {
        a = i;
        if (n % a == 0) {
            b = n / a;
            break;
        }
    }

    int ret = max(int(log10(a)) + 1, int(log10(b)) + 1);

    cout << ret << endl;

    return 0;
}