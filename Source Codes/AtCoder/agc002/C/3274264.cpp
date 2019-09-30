#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

long long N, L;
long long a[100005];

int main()
{
    cin >> N >> L;

    for (int i = 0; i < N;i++)
    {
        cin >> a[i];
    }

    int p = -1;

    for (int i = 0; i < N - 1;i++)
    {
        if(a[i] + a[i + 1] >= L)
        {
            p = i;
            break;
        }
    }

    if(p == -1)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;

    for (int i = 0; i < p;i++)
    {
        cout << i + 1 << endl;
    }
    for (int i = N - 2; p <= i; i--)
    {
        cout << i + 1 << endl;
    }

    return 0;
}