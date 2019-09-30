#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;

    double ha = 0.5 * ((60 * (n % 12)) + m);
    double ma = 6.0 * m;
    double ans = max(ha, ma) - min(ha, ma);
    if(ans > 180.0) ans = 360.0 - ans;
    cout << ans << endl;
    return 0;
}