// progb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

int parlis[1000][1000];
int edgeanses[1000][1000];
int trinodes[1000][3]; //newest node comes last

vector<vector<int> >chdlis;

int ans[1000];

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int n,i,j,k;
		
		//int ans  = 0;
		memset(parlis,0,sizeof(parlis));
		memset(trinodes,0,sizeof(trinodes));
		chdlis.clear();

		fin >> n;

		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				parlis[i][j]=-1;
			}
		}
		for(i=0; i<3; i++)
		{
			for(j=i+1; j<3; j++)
			{
				parlis[j][i]=parlis[i][j]=0;
			}
		}
		trinodes[0][0]=0;
		trinodes[0][1]=1;
		trinodes[0][2]=2;

		vector<int> empt;

		chdlis.push_back(empt);

		int a,b,p;
		for(i=3; i<n;i++)
		{
			fin >> a >> b;
			a--;
			b--;
			
			if(a>b)
			{
				k=a;
				a=b;
				b=k;
			}
			p = parlis[a][b];
			//cout << i << " " << a << " " << b << " " << p  << endl;
			parlis[a][i]=parlis[i][a]=parlis[b][i]=parlis[i][b]=i-2;
			chdlis.push_back(empt);
			chdlis[p].push_back(i-2);
			trinodes[i-2][0]=a;
			trinodes[i-2][1]=b;
			trinodes[i-2][2]=i;
		}
		//cout << "Hello" << endl;
		for(i=n-3; i>=0; i--)
		{
			int ans1,ans2,ans3;
			ans1 = ans2= ans3=0;
			for(j=0; j<chdlis[i].size(); j++)
			{
				//cout << j << " ";
				k = chdlis[i][j];
				//cout << k << endl;
				if((trinodes[k][0]==trinodes[i][0] || trinodes[k][1]==trinodes[i][0]) && (trinodes[k][0]==trinodes[i][2] || trinodes[k][1]==trinodes[i][2]))
				{
					if(ans[k]>ans1)
					{
						ans1=ans[k];
					}
				}
				else if((trinodes[k][0]==trinodes[i][1] || trinodes[k][1]==trinodes[i][1]) && (trinodes[k][0]==trinodes[i][2] || trinodes[k][1]==trinodes[i][2]))
				{
					if(ans[k]>ans2)
					{
						ans2=ans[k];
					}
				}
				else
				{
					if(ans[k]>ans3)
						ans3=ans[k];
				}

			}
			//cout << i << " " << ans1 << " " << ans2 << " " << ans3 << " ";
			if(ans1>=3)
			{
				ans1-=2;
			}
			if(ans2>=3)
			{
				ans2-=2;
			}
			if(ans3>=3)
			{
				ans3-=2;
			}
			edgeanses[trinodes[i][0]][trinodes[i][2]]=edgeanses[trinodes[i][2]][trinodes[i][0]]=ans1;
			edgeanses[trinodes[i][1]][trinodes[i][2]]=edgeanses[trinodes[i][2]][trinodes[i][1]]=ans2;
			if(i==0)
			{
				edgeanses[trinodes[i][0]][trinodes[i][1]]=ans3;
			}
			ans[i]= ans1+ans2+ans3+3;
			//cout << ans[i] << endl;
		}

		int best = ans[0];
		cout << ans[0] << endl;
		for(i=n-3; i>=1; i--)
		{
			int ans1 = edgeanses[trinodes[i][0]][trinodes[i][1]];
			int p = parlis[trinodes[i][0]][trinodes[i][1]];
			int ans2 = edgeanses[trinodes[i][0]][trinodes[i][2]];
			int ans3 = edgeanses[trinodes[i][1]][trinodes[i][2]];
			ans1 = 0;

			for(j=0; j<chdlis[p].size(); j++)
			{
				//cout << j << " ";
				
				k = chdlis[p][j];
				if(k==i)
					continue;
				//cout << k << endl;
				if(ans1 < ans[k])
					ans1= ans[k];

			}
			if(ans1>=3)
				ans1-=2;
			if(ans1+ans2+ans3+3>best)
			{
				best = ans1+ans2+ans3+3;
			}
		}
		
		cout << "Case #" << ct << ":" << " " << best << endl;
		fout << "Case #" << ct << ":" << " " << best << endl;
		
	}
	
	
	return 0;
}

