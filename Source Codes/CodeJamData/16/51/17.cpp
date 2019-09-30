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
const int MAXN = 20100;

ifstream fin ("A.in");
ofstream fout ("A.out");

string S;
char q[MAXN];
int nq;

int main()
{
    int ntest = 0; fin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
    nq = 0;
    fin >> S;

    int score = S.length() / 2;
    for (int i = 0; i < S.length(); i++)
    {
    	if (nq == 0 || q[nq-1] != S[i])
    	{
    		q[nq++] = S[i];
    	}
    	else
    	{
    		score++;
    		nq--;
    	}
    }

    fout << "Case #" << test << ": ";
    fout << score * 5 << "\n";
    }
    return 0;
}
