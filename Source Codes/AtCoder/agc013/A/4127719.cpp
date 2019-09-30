#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long N;
vector<long long> a;

int main()
{
    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int ans = 1;

    int f = 0;
    int prev = a[0];
    for (int i = 1; i < N; i++)
    {
        if(f == 0)
        {
            if(prev < a[i])
            {
                f = 1;
            }
            else if(prev > a[i])
            {
                f = -1;
            }
        }
        else
        {
            if ((f == 1 && prev > a[i]) || (f == -1 && prev < a[i]))
            {
                f = 0;
                ans++;
            }
        }
        prev = a[i];
    }

    cout << ans << endl;

    return 0;
}