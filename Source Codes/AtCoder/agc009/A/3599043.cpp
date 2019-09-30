#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

long long A[100005];
long long B[100005];

int main()
{
    long long N;

    cin >> N;

    long long ans = 0;

    for (long long i = 0; i < N;i++)
    {
        cin >> A[i] >> B[i];
    }

    for (long long i = N - 1; i >= 0;i--)
    {
        if((ans + A[i]) % B[i] != 0)
        {
            ans += B[i] - (ans + A[i]) % B[i];
        }
    }

    cout << ans << endl;

    return 0;
}