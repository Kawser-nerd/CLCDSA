// progc.cpp : Defines the entry point for the console application.
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

bool cando[61][41][21][21];

bool can(int a, int b, int c, int d)
{
	if(a<0 || b<0 || c<0)
		return false;
	return cando[a][b][c][d];
}

int solve2(int n)
{
	memset(cando,0,sizeof(cando));
	int i,j,k,l;
	for(i=0; i<=2*n; i++)
	{
		for(j=0;j<=n; j++)
		{
			for(k=0; k<=n; k++)
			{
				bool ans = true;
				if(k==0)
				{
					ans = true;
				}
				else
				{
					ans = (can(i-2,j,0,k-1) || can(i,j-1,0,k-1)) && can(i-1,j,0,k-1);
				}
				cando[i][j][0][k]=ans;
			}
		}
	}
	int min = 2*n;
	for(i=0; i<=n; i++)
	{
		if(can(2*n-2*i,i,0,n))
		{
			min = 2*n-i;
		}
	}
	//cout << can(4,1,0,3) << endl;
	//cout << can(2,1,0,2) << endl;
	//cout << can(3,1,0,2) << endl;
	return min;
}


int solve3(int n)
{
	bool dbg = false;
	int i,j,k,l;
	int _ans = 3*n;
	for(i=0; i<=3*n; i++)
	{
		for(j=0; j<=2*n; j++)
		{
			if(i+2*j > 3*n)
				continue;
			for(k=0; k<=n; k++)
			{
				if(i+2*j+3*k>3*n)
					continue;
				for(l=0; l<=n; l++)
				{
					if(i==1 && j==1 && k==1 && l==2)
					{
						dbg = false;
					}
					else
					{
						dbg= false;
					}
					if(l==0)
					{
						cando[i][j][k][l]=true;
						continue;
					}
					bool ans = true;
					ans = ans && can(i-1,j,k,l-1);
					if(dbg)
					{
						cout << ans << endl;
					}

					ans = ans && ( can(i-2,j,k,l-1) || can(i,j-1,k,l-1));
					if(dbg)
					{
						cout << ans << endl;
					}

					ans = ans && ( can(i-3,j,k,l-1) || can(i-1,j-1,k,l-1) || can(i,j,k-1,l-1));
					if(dbg)
					{
						cout << ans << endl;
					}
					cando[i][j][k][l]=ans;
					if(ans && (i + 2*j + 3*k == n*3) && l==n)
					{
						if(i+j+k<_ans)
						{
							_ans=i+j+k;
							cout << i << " " << j << " " << k << endl;
						}
					}
				}
			}
		}
	}
	
	return _ans;
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
		
		int ans  = 0;
		int C;

		fin >> k >> C;

		if(C==1)
			ans = k;
		else if(C==2)
			ans = solve2(k);
		else
			ans= solve3(k);
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
	}
	
	
	return 0;
}

