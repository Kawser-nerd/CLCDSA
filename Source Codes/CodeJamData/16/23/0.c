#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N;
int mat[3000][3000];
int vis[3000],link[3000];
int mm,nn;

int find(int x)
{
	int i,j,k;
	for(i=0; i<nn; i++)
	{
		if (mat[x][i] && !vis[i])
		{
			vis[i] = 1;
			if (link[i] < 0 || find(link[i]))
			{
				link[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i,j,k;
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N;
		map<string,int> ma; map<string,int> mb;
		vector<pair<string,string> > all;
		for(i=0; i<N; i++)
		{
			string a,b;
			cin >> a >> b;
			if (ma.find(a) == ma.end())
			{
				ma[a] = ma.size();
			}
			if (mb.find(b) == mb.end())
			{
				mb[b] = mb.size();
			}
			all.push_back(make_pair(a,b));
		}
		mm = ma.size(); nn = mb.size();
		for(i=0; i<mm; i++) for(j=0; j<nn; j++) mat[i][j] = 0;
		for(i=0; i<all.size(); i++)
		{
			mat[ma[all[i].first]][mb[all[i].second]] = 1;
		}
		memset(link, 0xff, sizeof(link));
		int s=0;
		for(i=0; i<mm; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (find(i))
				s++;
		}
		int r = mm+nn;
//		printf("%d %d %d\n", all.size(), r, s);
		printf("Case #%d: %d\n", cc, all.size()-r+s);
	}
}
