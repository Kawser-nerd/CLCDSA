#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 2e5;

int bit[MAX_N + 1];

int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, int x)
{
    while(i <= MAX_N + 1)
    {
        bit[i] += x;
        i += i & -i;
    }
}
int bs(int X)
{
    int l = 0;
    int r = MAX_N;
    int m = (l + r) / 2;
    while(r - l != 1)
    {
        int x = sum(m);
        if(x < X)
        {
            l = m;
        }
        else
        {
            r = m;
        }
        m = (l + r) / 2;
    }
    add(r, -1);
    return r;
}

int main()
{
    int Q;
    cin >> Q;
    for (int i = 0; i < Q;i++)
    {
        int T, X;
        cin >> T >> X;
        if (T == 1)
        {
            add(X, 1);
        }
        else
        {
            cout << bs(X) << endl;
        }
    }
    return 0;
}