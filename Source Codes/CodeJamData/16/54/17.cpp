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
const int MAXN = 110;

ifstream fin ("D.in");
ofstream fout ("D.out");

int N, L;
string p[MAXN];

char opp (char ch)
{
	if (ch == '0') return '1';
	return '0';
}

int main()
{

    int ntest = 0; fin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
    fin >> N >> L;
    for (int i = 0; i < N; i++)
    {
    	fin >> p[i];
    }

    fout << "Case #" << test << ": ";

    string s;
    fin >> s;

    bool bad = false;
    for (int i = 0; i < N; i++)
    {
    	bool seen = true;
    	for (int j = 0; j < L; j++)
    	{
    		if (p[i][j] != s[j])
    			seen = false;
    	}
    	if (seen) bad = true;
    }

    if (bad)
    {
    	fout << "IMPOSSIBLE\n";
    }
    else
    {
    	for (int i = 0; i < L; i++)
    	{
    		fout << opp (s[i]) << '?';
    	}
    	fout << ' ';
    	for (int i = 0; i < L - 1; i++)
    	{
    		fout << opp (s[i]) << s[i];
    	}
    	fout << opp (s[L-1]);
    	fout << '\n';
    }

    }
    return 0;
}
