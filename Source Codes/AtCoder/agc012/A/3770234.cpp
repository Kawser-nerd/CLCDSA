#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    long long ans = 0;
    int itr;
    cin >> n;
    vector<long long> a(3 * n);
    for (int i=0; i< 3 * n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i=1; i<=n; ++i){
        itr = 3 * n - 2 * i;
        ans += a[itr];
    }
    cout << ans << endl;
}