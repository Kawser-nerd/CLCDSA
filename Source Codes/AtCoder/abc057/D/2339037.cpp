#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
#include <iomanip>

using namespace std;

using ll = long long;

ll pascal[51][51];

void make_table()
{
    for (int n = 0; n < 51;n++)
    {
        for (int r = 0; r <= n;r++)
        {
            if(r == n || r == 0)
            {
                pascal[n][r] = 1LL;
            }
            else
            {
                pascal[n][r] = pascal[n - 1][r - 1] + pascal[n - 1][r];
            }
        }
    }
}

int main()
{
    int N, A, B;
    vector<ll> v;

    cin >> N >> A >> B;

    v.resize(N);

    make_table();

    for (int i = 0; i < N;i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<ll>());

    ll sum = accumulate(v.begin(), v.begin() + A, 0LL);

    double ans = sum / (double)A;

    ll num;
    if (v[0] != v[A - 1])
    {    
        int cntn = count(v.begin(), v.end(), v[A - 1]);
        int cntr = count(v.begin(), v.begin() + A, v[A - 1]);
        num = pascal[cntn][cntr];
    }
    else
    {
        num = 0;
        int cntn = count(v.begin(), v.end(), v[A - 1]);
        for (int i = A; i <= B; i++)
        {
            int cntr = i;
            num += pascal[cntn][cntr];
        }

    }

    cout << fixed;
    cout << setprecision(6) << ans << endl << num << endl;

    return 0;
}