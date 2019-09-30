#include <iostream>
using namespace std;
long long n, x, ans;
long long cel(long long n, long long x) {
    if(n % x == 0)
        return 2 * n - x;
    ans = n / x * 2 * x + cel(x, n % x);
    return ans ;
}
int main()
{
    while(cin >> n >> x) {
        ans = cel(n - x, x) + n;
        cout << ans << endl;
    }
}