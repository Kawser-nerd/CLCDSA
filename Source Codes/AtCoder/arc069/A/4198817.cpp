#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main()
{
    long long n;
    long long m;
    cin >> n >> m;
    long long ans = 0;
    if(2 * n <= m){
        ans += n;
        m -= 2 * n;
        ans += m / 4;
    }
    else {
        ans += min(m / 2, n);
    }
    cout << ans << endl;
    return 0;
}