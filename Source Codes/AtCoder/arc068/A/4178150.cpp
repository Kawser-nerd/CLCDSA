#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    long long m = x / 11;
    long long d = x - m * 11;
    long long ans;
    if(d == 0){
        ans = 2 * m;
    }
    else {
        ans = 2 * m + ((d <= 6) ? 1 : 2);
    }
    cout << ans << endl;
    return 0;
}