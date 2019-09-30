#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int n = 0;
    int ans = 0;
    vector<int> p(n);
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(p.begin(), p.end());
    for (size_t i = 0; i < n - 1; i++)
    {
        ans += p[i];
    }
    ans += p[n - 1] / 2;
    cout << ans << endl;
    return 0;
}