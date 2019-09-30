#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    int x[m];

    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    sort(x, x+m);

    if (m > n) {
        int distance[m-1];
        for (int i = 0; i < m-1; i++) {
            distance[i] = x[i+1] - x[i];
        }
        sort(distance, distance + m - 1);
        int ans = 0;
        for (int i = 0; i < m - n; i++) {
            ans += distance[i];
        }
        cout << ans << endl;
    }
    else {
        cout << 0 << endl;
    }
}