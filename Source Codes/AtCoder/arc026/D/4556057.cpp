#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

const long long maxn = 1e5 + 1;

long long par[maxn];
long long r[maxn];

void init(long long n)
{
    for (int i = 0; i < n;i++)
    {
        r[i] = 0;
        par[i] = i;
    }
}
long long find(long long x)
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
void unite(long long x, long long y)
{
    x = find(x);
    y = find(y);
    if(x == y)
    {
        return;
    }
    else if(r[x] < r[y])
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
bool same(long long x, long long y)
{
    return find(x) == find(y);
}

int main(){
    long long N, M;
    cin >> N >> M;
    vector<pair<double, long long> > w(M);
    vector<long long> A(M), B(M);
    vector<double> C(M), T(M);
    for (long long i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> T[i];
    }
    double le = 0.0;
    double ri = 1e9;
    double ans = ri;
    for (long long bt = 1; bt <= 100; bt++)
    {
        init(N);
        double x = (le + ri) / 2.0;
        for (long long i = 0; i < M; i++)
        {
            w[i] = make_pair(C[i] - T[i] * x, i);
        }
        sort(w.begin(), w.end());
        double sum = 0;
        for (long long i = 0; i < M; i++)
        {
            double w1 = w[i].first;
            long long w2 = w[i].second;
            long long from = A[w2];
            long long to = B[w2];
            if (same(from, to) == false || w1 < 0)
            {
                sum += w1;
                unite(from, to);
            }
        }
        if (sum <= 0.0)
        {
            ri = x;
        }
        else
        {
            le = x;
        }
    }
    //cout << ri << endl;
    printf("%.10f\n", ri);
    return 0;
}