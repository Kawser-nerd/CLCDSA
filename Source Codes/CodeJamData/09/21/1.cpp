#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class Node
{
public:
	long double w;
	string ftr;
	int lft, rgt;
};

int l;
string dtree;
vector<Node> ptree;
int root;

int ParseTree(string &s)
{
	istringstream iss(s);
	char c = iss.get();
	while (c != '(') c = iss.get();
	Node tn;
	iss >> tn.w;
	c = iss.get();
	while (1)
	{
		if (c == ')')
		{
			tn.lft = tn.rgt = -1;
			tn.ftr = "";
			ptree.push_back(tn);
			return ptree.size() - 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			tn.ftr = "";
			while (c >= 'a' && c <= 'z')
			{
				tn.ftr += c;
				c = iss.get();
			}
			int cb = 0;
			string cs = "";
			vector<string> ts;
			while (! (cb == 0 && c == ')'))
			{
				cs += c;
				if (c == '(') cb++;
				if (c == ')')
				{
					if (cb == 1) 
					{
						ts.push_back(cs);
						cs = "";
					}
					cb--;
				}
				c = iss.get();
			}
			tn.lft = ParseTree(ts[0]);
			tn.rgt = ParseTree(ts[1]);
			ptree.push_back(tn);
			return ptree.size() - 1;
		}
		c = iss.get();
	}
	return -1;
}

void Load()
{
	dtree = "";
	scanf("%d", &l);
	char c = getchar();
	while (c != 10) c = getchar();
	int i;
	for (i = 0; i < l; i++)
	{
		c = getchar();
		while (c != 10)
		{
			dtree += c;
			c = getchar();
		}
		dtree += ' ';
	}
	ptree.clear();
	root = ParseTree(dtree);
}


void Solve()
{
	int a;
	scanf("%d", &a);
	int i;
	for (i = 0; i < a; i++)
	{
		string name;
		cin >> name;
		set<string> have;
		have.clear();
		int n, j;
		cin >> n;
		for (j = 0; j < n; j++)
		{
			string r;
			cin >> r;
			have.insert(r);
		}
		long double p = 1;
		int cver = root;
		while (cver != -1)
		{
			p *= ptree[cver].w;
			if (ptree[cver].ftr != "")
			{
				if (have.find(ptree[cver].ftr) == have.end()) cver = ptree[cver].rgt;
				else cver = ptree[cver].lft;
			}
			else break;
		}
		printf("%.10lf\n", (double)p);
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int nt, it;
	scanf("%d", &nt);
	for (it = 0; it < nt; it++)
	{
		printf("Case #%d:\n", it + 1);
		Load();

		Solve();
	}
	return 0;
}