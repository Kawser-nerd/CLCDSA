#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m;
    long long ans;
    const long long d = 1000000007;
    cin >> n >> m;
    if(abs(n - m) > 1){
        ans = 0;
    }
    else {
        ans = (n == m) ? 2 : 1;
        for(int i=n; i>0; --i){
            ans *= i;
            ans = ans % d;
        }
        for(int i=m; i>0; --i){
            ans *= i;
            ans = ans % d;
        }
    }
    cout << ans << endl;
}