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
    int si, ei;
    int ans = 0;
    cin >> si >> ei; ans += (si / 10) * ei;
    cin >> si >> ei; ans += (si / 10) * ei;
    cin >> si >> ei; ans += (si / 10) * ei;
    cout << ans << endl;
    return 0;
}