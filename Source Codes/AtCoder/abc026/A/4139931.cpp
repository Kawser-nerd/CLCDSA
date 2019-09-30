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
    int A;
    cin >> A;

    int ans = 0;
    for(int x = 1; x < A; ++x)
    {
        int y = A - x;
        ans = max(ans, x * y);
    }
    cout << ans << endl;
    return 0;
}