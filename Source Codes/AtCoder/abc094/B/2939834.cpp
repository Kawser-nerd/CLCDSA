#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, m, x; cin >> n >> m >> x;
    vector<int> v;
    // int a[110] = {0};

    for (int i = 0; i <= n; i++) v.push_back(0);

    for (int i = 1; i <= m; i++) {
        int p; cin >> p;
        v[p] = 1;
    }

    cout << (min(count(v.begin(), v.begin() + x, 1), count(v.begin() + x, v.end(), 1))) << endl;

    return 0;
}