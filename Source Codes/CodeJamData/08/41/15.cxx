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


long long tots[9];

int values[10000][2];
int types[10000];
int changes[10000];
int startvals[10000];

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
		int v;
		cin >> m >> v;
		for(i=0; i<(m-1)/2; i++)
		{
			cin >> types[i] >> changes[i];
		}
		for(i=(m-1)/2; i<m; i++)
		{
			cin >> startvals[i];
			values[i][startvals[i]]=0;
			values[i][1-startvals[i]]=1000000;
		}
		for(k=(m-1)/2-1; k>=0; k--)
		{
			values[k][0]=values[k][1]=1000000;
			int c1=2*k+1;
			int c2=2*k+2;
			if(types[k]==0)
			{
				for(i=0; i<2; i++)
				{
					for(j=0; j<2; j++)
					{
						if(values[k][i|j]>values[c1][i]+values[c2][j])
						{
							values[k][i|j]=values[c1][i]+values[c2][j];
						}
					}
				}
			}
			if(types[k]==1 && changes[k]==1)
			{
				for(i=0; i<2; i++)
				{
					for(j=0; j<2; j++)
					{
						if(values[k][i|j]>values[c1][i]+values[c2][j]+1)
						{
							values[k][i|j]=values[c1][i]+values[c2][j]+1;
						}
					}
				}
			}
			if(types[k]==1)
			{
				for(i=0; i<2; i++)
				{
					for(j=0; j<2; j++)
					{
						if(values[k][i&j]>values[c1][i]+values[c2][j])
						{
							values[k][i&j]=values[c1][i]+values[c2][j];
						}
					}
				}
			}
			if(types[k]==0 && changes[k]==1)
			{
				for(i=0; i<2; i++)
				{
					for(j=0; j<2; j++)
					{
						if(values[k][i&j]>values[c1][i]+values[c2][j]+1)
						{
							values[k][i&j]=values[c1][i]+values[c2][j]+1;
						}
					}
				}
			}
		}
		cout << "Case #" << ct << ":" << " ";
		fout << "Case #" << ct << ":" << " ";
		if(values[0][v]>=1000000)
		{
			cout << "IMPOSSIBLE" << endl;
			fout << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << values[0][v] << endl;
			fout << values[0][v] << endl;
		}
		
	}

	
	return 0;
}

