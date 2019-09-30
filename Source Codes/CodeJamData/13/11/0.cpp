#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool check(long long r, long long c, long long t)
{
    long long a = 4 * r + 4 * c - 2;
    return double(a) * double(c) < 9e18 && a * c / 2 <= t;
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        long long r, t;
        cin >> r >> t;
        long long lef = 1, rig = t / r;
        while (lef < rig) {
            long long mid = (lef + rig + 1) / 2;
            if (check(r, mid, t))
                lef = mid;
            else
                rig = mid - 1;
        }
        cout << lef;
        printf("\n");
    }
    
    return 0;
}
