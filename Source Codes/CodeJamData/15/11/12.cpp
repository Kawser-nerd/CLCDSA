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
const int MAXN = 1100;

ifstream fin ("A.in");
ofstream fout ("A.out");

int N;
int m[MAXN];

int main()
{
    int ntest = 0;
    fin >> ntest;
    
    for (int test = 0; test < ntest; test++)
    {
        fin >> N;
        for (int i = 0; i < N; i++)
            fin >> m[i];
        
        int res = 0, res2 = 0;
        for (int i = 0; i < N - 1; i++)
        {
            if (m[i] > m[i+1])
            {
                res += m[i] - m[i+1];
                res2 = max (res2, m[i] - m[i+1]);
            }
        }
        
        int ans2 = 0;
        for (int i = 0; i < N - 1; i++)
            ans2 += min (m[i], res2);
        
        fout << "Case #" << test + 1 << ": " << res << " " << ans2 << "\n";
    }
    return 0;
}