#include <bits/stdc++.h>
using namespace std;

bool yes(long long n)
{
    string s = to_string(n);
    return is_sorted(s.begin(), s.end());
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt= 1; tt<=T; tt++)
    {
        printf("Case #%d: ", tt);
        long long n;
        cin >> n;

        if (yes(n))
        {
            cout << n << endl;
            continue;
        }

        for (long long i = 10;; i *= 10)
        {
            if (yes(n - n % i - 1))
            {
                cout << n - n % i - 1 << endl;
                break;
            }
        }
    }
}
