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

long long sols[2][15][5000000];

int solsizes[2][15];


void mksols(vector<long long> lis, int ct, int sgn)
{
	int n = lis.size();
	cout << "HELLO" << " " << n;
	cout << endl;
	if(n==0)
	{
		sols[ct][0][0]=0;
		solsizes[ct][0]++;
		return;
	}
	vector<long long> coeffs(n+1,0);
	int i,j,k;
	
	if(sgn==1)
	{
		vector<long long> tmplis(n,0);
		for(i=0; i<n; i++)
			tmplis[i]=lis[n-1-i];
		lis=tmplis;
	}
/*	for(i=0; i<n; i++)
	{
		cout << lis[i] << " ";
		
	}
	cout << endl;*/
	bool isok = true;
	long long tot = 0;
	int tp = 0;
	while(true)
	{
		//cout << "TRY " << coeffs[0] << " ";
		isok=true;
		tot = 0;
		tp = 0;
		k=0;
		int mxk = 0;
		for(i=0; i<n; i++)
		{
			if(coeffs[i]==0)
				continue;
			else if(coeffs[i]==2)
			{
				k++;
				tot += lis[i];
			}
			else
			{
				k--;
				tot-=lis[i];
			}
			if(k<0)
				isok=false;
		}
		//cout << isok << " " << tot << " " << k <<  endl;
		if(isok)
		{
			sols[ct][k][solsizes[ct][k]]=2*tot*sgn;
			solsizes[ct][k]++;
		}
		coeffs[0]++;
		if(coeffs[0]==1)
			coeffs[0]++;
		i=0;
		while(i<n && coeffs[i]==3)
		{
			coeffs[i]=0;
			coeffs[i+1]++;
			i++;
		}
		if(i==n)
			break;
	}
	for(i=0; i<=n; i++)
	{
		if(solsizes[ct][i]==0)
			continue;
		sort(sols[ct][i],sols[ct][i]+solsizes[ct][i]);
		/*cout << i << " ";
		for(j=0; j<solsizes[ct][i]; j++)
		{
			cout << sols[ct][i][j] << " ";
		}
		cout << endl;*/
	}

	

}

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
		memset(sols,0,sizeof(sols));
		memset(solsizes,0,sizeof(solsizes));
		long long f;
		

		fin >> n;
		vector<long long> planets(n,0);
		for(i=0; i<n; i++)
		{
			fin >> planets[i];
		}
		sort(planets.begin(), planets.end());
		fin >> f;
		int m = n/2;

		vector<long long> lisa;
		vector<long long> lisb;

		for(i=1; i<n-1; i++)
		{
			if(i<m)
			{
				lisa.push_back(planets[i]);
			}
			else
			{
				lisb.push_back(planets[i]);
			}
		}

		mksols(lisa,0,-1);
		mksols(lisb,1,1);
		long long ans = -1;
		long long extra = 2*(planets[n-1]-planets[0]);
		long long p,q,r;
		cout << extra << endl;
		for(i=0; i<15; i++)
		{
			if(solsizes[0][i]==0 || solsizes[1][i]==0)
				continue;
			int mx = solsizes[1][i]-1;
			for(j=0; j<solsizes[0][i]; j++)
			{
				while(mx>=0 && (sols[0][i][j]+sols[1][i][mx]+extra)>f)
					mx--;
				if(mx>=0 && sols[0][i][j]+sols[1][i][mx]+extra > ans)
				{
					ans=sols[0][i][j]+sols[1][i][mx]+extra;
				}
			}
		}
		if(ans>=0)
		{
			cout << "Case #" << ct << ":" << " " << ans << endl;
			fout << "Case #" << ct << ":" << " " << ans << endl;
		}
		else
		{
			cout << "Case #" << ct << ":" << " " << "NO SOLUTION" << endl;
			fout << "Case #" << ct << ":" << " " << "NO SOLUTION" << endl;
		}
		
	}
	
	
	return 0;
}

