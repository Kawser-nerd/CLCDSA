#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 110;

ifstream fin ("C.in");
ofstream fout ("C.out");

int N, Q;
ll mdist[MAXN], spd[MAXN];
ll fdist[MAXN][MAXN];
double rdist[MAXN][MAXN];

void run()
{
    fin >> N >> Q;
    for (int i = 0; i < N; i++)
        fin >> mdist[i] >> spd[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            fin >> fdist[i][j];
            if (fdist[i][j] == -1)
                fdist[i][j] = 1e12;
            if (i == j)
                fdist[i][j] = 0;
        }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                fdist[i][j] = min (fdist[i][j], fdist[i][k] + fdist[k][j]);
            }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (fdist[i][j] > mdist[i])
                rdist[i][j] = 1e12;
            else
                rdist[i][j] = fdist[i][j] / ((double) spd[i] + 0.0);
        }
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                rdist[i][j] = min (rdist[i][j], rdist[i][k] + rdist[k][j]);
            }

    for (int i = 0; i < Q; i++)
    {
        if (i) fout << " ";
        int s, e;
        fin >> s >> e;
        s--, e--;
        fout << rdist[s][e];
    }
}

int main()
{
    fout << fixed << setprecision(7);
    int T; fin >> T;
    for (int i = 1; i <= T; i++)
    {
        fout << "Case #" << i << ": ";
        run();
        fout << "\n";
    }
}