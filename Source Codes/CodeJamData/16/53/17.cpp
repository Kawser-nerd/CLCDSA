#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1100;

ifstream fin ("C.in");
ofstream fout ("C.out");


int N, S;
int x[MAXN], y[MAXN], z[MAXN];
double dist[MAXN];
bool seen[MAXN];

double sq (int k)
{
	return k * (double) k;
}

double edist (int i, int j)
{
	return sqrt (sq (x[i] - x[j]) + sq (y[i] - y[j]) + sq (z[i] - z[j]));
}

int main()
{
    int ntest = 0; fin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
    fin >> N >> S;
    for (int i = 0; i < N; i++)
    {
    	fin >> x[i] >> y[i] >> z[i];
    	int t = 0;
    	fin >> t >> t >> t;
    }

    for (int i = 0; i < N; i++)
    {
    	seen[i] = false;
    	dist[i] = 1e9;
    }
    dist[0] = 0;

    while (true)
    {
    	double bdist = 1e9;
    	int bloc = -1;
    	for (int i = 0; i < N; i++)
    		if (!seen[i] && dist[i] < bdist)
    		{
    			bdist = dist[i];
    			bloc = i;
    		}

    	if (bloc == -1) break;
    	seen[bloc] = true;
    	for (int i = 0; i < N; i++)
    	{
    		dist[i] = min (dist[i], max (dist[bloc], edist (i, bloc)));
    	}
    }

    fout << "Case #" << test << ": ";
    fout << fixed << setprecision (6);
    fout << dist[1] << "\n";
    }
    return 0;
}
