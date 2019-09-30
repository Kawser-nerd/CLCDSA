#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
lli MOD = 1000000;
int main()
{
    lli a[100005];
    lli n;
    cin >> n;
    lli b[100005];
    lli sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    lli sumn = n * (n + 1) / 2;
    if (sum % sumn) {
        cout << "NO" << endl;
        return 0;
    }
    lli l = sum / sumn;
    rep(i, n) b[i] = a[(i + 1) % n] - a[i];
    rep(i, n)
    {
        if (b[i] - l > 0 || ((-b[i] + l) % n)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}