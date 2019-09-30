#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

map<string,int> mp;

int ans[300][301][301];
int mvals[300];

bool cmp(pair<pair<int,int>,string> a, pair<pair<int,int>,string> b)
{
	return (a.first.second<b.first.second);
}

int main(void)
{
	int ttt;
	cin >> ttt;
	int ct = 0;
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k,l;
		int m,a,b,c;
		mp.clear();
		int n;
		cin >> n;
		string s;
		m=1;
		vector <pair<pair<int,int>,string> > lis;
		for(i=0; i<n; i++)
		{
			cin >> s >> j >> k;
			lis.push_back(make_pair(make_pair(j,k),s));
			//cout << s << " " << j << " " << k << endl;
			if(mp[s]==0)
			{
				mp[s]=m;
				m++;
			}
		}
		m--;
		cout << m << endl;
		for(i=0; i<n; i++)
		{
			for(j=0; j<=300; j++)
			{
				for(k=0; k<=300; k++)
				{
					ans[i][j][k]=10000;
				}
			}
		}
		int anses = 10000;
		sort(lis.begin(),lis.end(),cmp);
		for(i=0; i<n; i++)
		{
			mvals[i]=mp[lis[i].second];
		}
		for(i=0; i<n; i++)
		{
			if(lis[i].first.first==1)
			{
				for(j=1; j<=m; j++)
				{
					for(k=1; k<=m; k++)
					{
						ans[i][j][k]=1;
					}
				}
				if(lis[i].first.second==10000)
				{
					anses=1;
					//cout << "SPECIAL " << i << endl;
					//cout << lis[i].first.first << " " << lis[i].first.second << " " << lis[i].second << endl;
				}
			}
		}
		
		for(i=0; i<n && anses>1; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(lis[j].first.first>lis[i].first.second+1 || lis[j].first.second<=lis[i].first.second)
					continue;
				//cout << i << " " << j << endl;
				if(lis[j].second==lis[i].second)
				{
					for(k=1; k<=m; k++)
					{
						for(l=1; l<=m; l++)
						{
							if(ans[j][k][l]>ans[i][k][l]+1)
								ans[j][k][l]=ans[i][k][l]+1;
						}
					}
				}
				else
				{
					a=mvals[i];
					b=mvals[j];
					for(k=1; k<=m; k++)
					{
						if(ans[j][a][k]>ans[i][b][k]+1)
							ans[j][a][k]=ans[i][b][k]+1;
						if(ans[j][k][a]>ans[i][k][b]+1)
							ans[j][k][a]=ans[i][k][b]+1;
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(lis[i].first.second<10000)
				continue;
			for(j=1; j<=m; j++)
			{
				for(k=1; k<=m; k++)
				{
					if(ans[i][j][k]<anses)
					{
						anses=ans[i][j][k];
					}
				}
			}
		}
		if(anses>n)
		{
			cout << "Case #" << ct << ":" << " IMPOSSIBLE" << endl;
			fout << "Case #" << ct << ":" << " IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << ct << ":" << " " << anses << endl;
			fout << "Case #" << ct << ":" << " " << anses << endl;
		}
		
	}

	
	return 0;
}

	