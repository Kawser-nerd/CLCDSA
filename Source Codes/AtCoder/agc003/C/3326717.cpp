#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int N;
    vector<int> odd;
    vector<int> even;
    vector<int> a, b;

    cin >> N;
    a.resize(N);
    b.resize(N);
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        a[i] = A;
        b[i] = A;
    }

    map<int, int> m;
    sort(b.begin(), b.end());
    for (int i = 0; i < N; i++)
    {
        m[b[i]] = i;
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if(m[a[i]] % 2 == 0 && i % 2 == 1)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}