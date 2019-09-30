#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(auto& e : v)
    {
        cin >> e;
        e *= e;
    }
    sort(v.begin(), v.end(), greater<int>());
    int r2 = 0;
    int f = 1;
    for(auto& e : v)
    {
        r2 += e * f;
        f *= -1;
    }
    cout << std::setprecision(15) << (double)3.1415926535897932 * (double)r2 << endl;
    return 0;
}