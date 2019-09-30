#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

const long long mod = 1e9 + 7;

long long N;
long long C[200005];
long long last[200005];
long long num[200005];
long long acc[200005];

int main()
{
    cin >> N;
    num[0] = 1;
    C[0] = -1;
    for (long long i = 1; i <= N; i++)
    {
        cin >> C[i];
        long long lpos = last[C[i]];
        num[i] = num[i - 1];
        if (lpos != 0 && C[i] != C[i - 1])
        {
            acc[C[i]] += num[lpos - 1];
            acc[C[i]] %= mod;
            num[i] += acc[C[i]];
            num[i] %= mod;
        }
        if (C[i] != C[i - 1])
        {
            last[C[i]] = i;
        }
    }
    cout << num[N] << endl;
    return 0;
}