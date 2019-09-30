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

ifstream fin ("B.in");
ofstream fout ("B.out");

int N, M;
char ch[MAXN];
int par[MAXN];
vector <int> llist[MAXN];
vector <string> poss;
vector <int> osearch;

int ord[MAXN];
char res[110];

void dfs (int x)
{
	osearch.push_back (x);
	for (int i = 0; i < N; i++)
		if (par[i] == x)
		{
			dfs (i);
			for (int j = 0; j < llist[i].size(); j++)
				llist[x].push_back (llist[i][j]);
		}
	llist[x].push_back (x);
}

void grand()
{
	for (int i = 0; i < N; i++)
		ord[i] = i;
	for (int i = 0; i < N; i++)
	{
		int loc = rand() % (i + 1);
		swap (ord[i], ord[loc]);
	}
}

int main()
{
	srand (1722);

    int ntest = 0; fin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
    for (int i = 0; i < MAXN; i++)
    	llist[i].clear();
    poss.clear();
    osearch.clear();

    fin >> N;
    for (int i = 0; i < N; i++)
    {
    	fin >> par[i];
    	par[i]--;
    }
    for (int i = 0; i < N; i++)
    	fin >> ch[i];

    for (int i = 0; i < N; i++)
    	if (par[i] == -1)
    		dfs (i);

    for (int i = 0; i < 6000; i++)
    {
    	grand();
    	for (int j = 0; j < N; j++)
    	{
    		int cloc = osearch[j];
    		int lo = 1e9, loc = -1;

    		for (int k = 0; k < llist[cloc].size(); k++)
    		{
    			int kid = llist[cloc][k];
    			if (ord[kid] < lo)
    			{
    				lo = ord[kid];
    				loc = kid;
    			}
    		}

    		swap (ord[cloc], ord[loc]);
    	}

    	for (int j = 0; j < N; j++)
    		res[ord[j]] = ch[j];
    	res[N] = '\0';

    	string s(res);
    	poss.push_back (s);
    }

    fout << fixed << setprecision (4);
    fout << "Case #" << test << ":";

    fin >> M;
    for (int i = 0; i < M; i++)
    {
    	string s; fin >> s;

    	int cnt = 0;
    	for (int j = 0; j < poss.size(); j++)
    	{
    		bool good = false;
    		for (int k = 0; k <= poss[j].length() - s.length(); k++)
    		{
    			for (int l = 0; l < s.length(); l++)
    			{
    				if (poss[j][k+l] != s[l])
    				{
    					break;
    				}
    				if (l + 1 == s.length())
    					good = true;
    			}

    			if (good) break;
    		}
    		if (good) cnt++;
    	}

    	fout << " " << (cnt + 0.) / poss.size();
    }
    fout << "\n";

    }
    return 0;
}
