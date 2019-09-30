#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

static bool test_prime(ll p)
{
    if (p < 2) return false;
    for (ll i = 2; i * i <= p; i++)
        if (p % i == 0)
            return false;
    return true;
}

static int parent[1000001];

static int root(int x)
{
    if (parent[x] < 0)
        return x;
    else
        return parent[x] = root(parent[x]);
}

static void merge(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a == b) return;
    if (parent[a] > parent[b])
        swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
}

int main()
{
    int cases;
    cin >> cases;

    for (int cas = 0; cas < cases; cas++)
    {
        ll A, B, P;
        cin >> A >> B >> P;

        for (ll i = A; i <= B; i++)
            parent[i - A] = -1;
        for (ll i = P; i <= B - A; i++)
            if (test_prime(i))
            {
                ll t = B - B % i;
                while (t - i >= A)
                {
                    merge(t - A, t - i - A);
                    t -= i;
                }
            }
        ll ans = 0;
        for (ll i = A; i <= B; i++)
            if (parent[i - A] < 0)
                ans++;
        cout << "Case #" << cas + 1 << ": " << ans << "\n";
    }
    return 0;
}
