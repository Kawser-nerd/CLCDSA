#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n = 0;
    long long h = 0;
    long long a_max = 0;
    vector<int> b_list = {};

    cin >> n >> h;

    int i = 0;
    long long a = 0;
    long long b = 0;
    while (i < n && cin >> a >> b)
    {
        if (a > a_max)
        {
            a_max = a;
        }
        b_list.push_back(b);
        ++i;
    }

    long long cnt = 0;
    sort(b_list.begin(), b_list.end(), greater<int>());
    for (auto j = b_list.begin(); j != b_list.end(); ++j)
    {
        if (*j > a_max)
        {
            h -= *j;
            ++cnt;
        }

        if (h <= 0)
        {
            cout << cnt << endl;
            return 0;
        }
    }

    cnt += h / a_max;
    if (h % a_max > 0)
    {
        ++cnt;
    }

    cout << cnt << endl;

    return 0;
}