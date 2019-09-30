#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const long long M = 1e9 + 7;

int main()
{
    int N;

    cin >> N;

    int p = N % 2;

    vector<int> cnt((N+1)/2, 0);

    bool f = true;

    if(p == 1)
    {
        int A;
        for (int i = 0; i < N;i++)
        {
            cin >> A;
            if(A % 2 == 1)
            {
                f = false;
                break;
            }
            cnt[A / 2]++;
        }
        if(cnt[0] != 1)
        {
            f = false;
        }
        int n = (N+1) / 2;
        for (int i = 1; i < n;i++)
        {
            if(cnt[i] != 2)
            {
                f = false;
                break;
            }
        }
    }
    else
    {
        int A;
        for (int i = 0; i < N; i++)
        {
            cin >> A;
            if (A % 2 == 0)
            {
                f = false;
                break;
            }
            cnt[A / 2]++;
        }
        int n = N / 2;
        for (int i = 0; i < n;i++)
        {
            if(cnt[i] != 2)
            {
                f = false;
                break;
            }
        }
    }

    long long pp = 1;
    int n = N / 2;
    for (int i = 0; i < n;i++)
    {
        pp *= 2;
        pp = pp % M;
    }
    long long ans = f == false ? 0LL : pp;
    cout << ans << endl;

    return 0;
}