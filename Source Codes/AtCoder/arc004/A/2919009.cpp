#include <iostream>
#include <algorithm>
#include <math.h>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x[n][2];
    int m = 0;
    REP(i, n) { cin >> x[i][0] >> x[i][1]; }
    REP(i, n)
    {
        for (int j = i; j < n; j++)
        {
            int dist = (x[i][0] - x[j][0]) * (x[i][0] - x[j][0]) + (x[i][1] - x[j][1]) * (x[i][1] - x[j][1]);
            m = max(dist, m);
        }
    }
    cout << sqrt(m) << endl;
    return 0;
}