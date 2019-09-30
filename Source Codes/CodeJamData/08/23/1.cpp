#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

static vector<int> deck;
static vector<int> op;

static void bit_add(size_t x, int v)
{
    x++;
    while (x < op.size())
    {
        op[x] += v;
        x += x & -x;
    }
}

static int bit_get(size_t x)
{
    x++;
    int ans = 0;
    while (x)
    {
        ans += op[x];
        x &= x - 1;
    }
    return ans;
}

static int bit_find(int s)
{
    int l = -1;
    int r = op.size() - 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (bit_get(m) >= s)
            r = m;
        else
            l = m;
    }
    return r;
}

int main()
{
    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int K, n;
        cin >> K >> n;
        vector<int> D(n);
        for (int i = 0; i < n; i++)
        {
            cin >> D[i];
            D[i]--;
        }

        deck.clear();
        deck.resize(K, -1);

        op.clear();
        op.resize(K + 2, 0);
        for (int i = 0; i < K; i++)
            bit_add(i, 1);

        int p = 0;
        for (int i = 0; i < K; i++)
        {
            p += i;
            p %= K - i;
            int slot = bit_find(p + 1);
            assert(deck[slot] == -1);
            deck[slot] = i + 1;
            bit_add(slot, -1);
        }

        cout << "Case #" << cas + 1 << ":";
        for (int i = 0; i < n; i++)
            cout << " " << deck[D[i]];
        cout << "\n";
    }
    return 0;
}
