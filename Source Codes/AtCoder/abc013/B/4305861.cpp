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
    int a, b;
    cin >> a >> b;

    int d = (a < b ? 1 : -1);
    if(abs(a - b) >= 5)
        d *= -1;
    
    int ans = 0;
    while(a != b)
    {
        ans++;
        a = (a + d + 10) % 10;
    }
    cout << ans << endl;
    return 0;
}