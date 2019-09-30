#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int par[maxn];
int r[maxn];

void init(int n)
{
    for (int i = 0; i < n;i++)
    {
        par[i] = i;
        r[i] = 0;
    }
}
int find(int x)
{
    if(par[x] == x)
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (r[x] < r[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if(r[x] == r[y])
        {
            r[x]++;
        }
    }
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> p;
    init(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        a--;
        p.push_back(a);
    }
    for (int i = 0; i < M;i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        unite(x, y);
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(p[i] == i || same(i, p[i]) == true)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}