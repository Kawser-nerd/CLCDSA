#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 3100;

ifstream fin ("C.in");
ofstream fout ("C.out");

int N;
int x[MAXN], y[MAXN];
vector <int> xval, yval;
pair <int, int> pnt[MAXN];

inline bool cmp (pair <int, int> left, pair <int, int> right)
{
    if (left.second > 0 && right.second < 0)
        return true;
    if (left.second < 0 && right.second > 0)
        return false;
    if (left.second == 0)
    {
        if (left.first > 0)
            return (right.second != 0 || right.first < 0);
        else
            return right.second < 0;
    }
    if (right.second == 0)
    {
        if (right.first > 0)
            return false;
        else
            return left.second > 0;
    }
    
    return left.first * (ll) right.second > right.first * (ll) left.second;
}

bool bad (pair <int, int> left, pair <int, int> right)
{
    return left.first * (ll) right.second > right.first * (ll) left.second;
}

// max contact
int calc()
{
    int M = (int) xval.size();
    for (int i = 0; i < M; i++)
        pnt[i] = make_pair (xval[i], yval[i]);
    
    sort (pnt, pnt + M, cmp);
    
    /*cout << "test\n";
    for (int i = 0; i < M; i++)
    {
        cout << pnt[i].first << " " << pnt[i].second << "\n";
    }*/
    
    int lo = 0, ans = 0;
    for (int i = 0; i < M; i++)
    {
        while (bad (pnt[i], pnt[lo]))
            lo++;
        ans = max (ans, i - lo + 1);
    }
    return ans;
}

int solve (int m)
{
    xval.clear();
    yval.clear();
    
    for (int i = 0; i < N; i++)
    {
        if (i == m) continue;
        xval.push_back (x[i] - x[m]);
        yval.push_back (y[i] - y[m]);
    }
    
    int r = calc();
    for (int i = 0; i < xval.size(); i++)
    {
        xval[i] = -xval[i];
        yval[i] = -yval[i];
    }
    
    return N - 1 - max (r, calc());
}

int main()
{
    int ntest = 0;
    fin >> ntest;
    
    for (int test = 0; test < ntest; test++)
    {
        fin >> N;
        for (int i = 0; i < N; i++)
            fin >> x[i] >> y[i];
        
        fout << "Case #" << test + 1 << ":\n";
        for (int i = 0; i < N; i++)
            fout << solve(i) << "\n";
    }
    return 0;
}