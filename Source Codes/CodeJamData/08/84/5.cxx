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

int masktoi[1024];
int itomask[1024];
long long mymat[252][252][40];

long long ansmat[252][252][2];

long long mod=30031;

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
		int n,p;
		memset(masktoi,0,sizeof(masktoi));
		memset(itomask,0,sizeof(itomask));
		memset(mymat,0,sizeof(mymat));
		memset(ansmat,0,sizeof(ansmat));
		cin >> n >> k >> p;
		m=0;
		for(i=0; i<(1<<p); i++)
		{
			l=0;
			for(j=0; j<p; j++)
			{
				if((1<<j)&i)
					l++;
			}
			if(l==k && i>=(1<<(p-1)))
			{
				masktoi[i]=m;
				itomask[m]=i;
				m++;
			}
			else
			{
				masktoi[i]=-1;
			}
		}
		cout << m << endl;
		for(i=0; i<(1<<p); i++)
		{
			if(masktoi[i]==-1)
				continue;
			if(i%2==1)
			{
				j=i/2;
				j+=(1<<(p-1));
				mymat[masktoi[j]][masktoi[i]][0]=1;
			}
			else
			{
				j=i/2;
				for(l=0; l<p-1; l++)
				{
					if((1<<l)&j)
					{
						a=j-(1<<l)+(1<<(p-1));
						mymat[masktoi[a]][masktoi[i]][0]=1;
					}
				}
			}
		}
		
		for(a=0; a<29; a++)
		{
			for(i=0; i<m; i++)
			{
				for(j=0; j<m; j++)
				{
					for(l=0; l<m; l++)
					{
						mymat[i][j][a+1]+=mymat[i][l][a]*mymat[l][j][a];
						mymat[i][j][a+1]%=mod;
					}
				}
			}
		}
		/*if(m<10)
		{
			for(a=0; a<5; a++)
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<m; j++)
					{
						cout << mymat[i][j][a] << " ";
					}
					cout << endl;
				}
				cout <<endl;
			}
		}*/
		for(i=0; i<m; i++)
		{
			ansmat[i][i][0]=1;
		}
		int curr=0;
		for(a=0; a<30; a++)
		{
			if((1<<a)&(n-k))
			{
				for(i=0; i<m; i++)
				{
					for(j=0; j<m; j++)
					{
						ansmat[i][j][1-curr]=0;
						for(l=0; l<m; l++)
						{
							ansmat[i][j][1-curr]+=ansmat[i][l][curr]*mymat[l][j][a];
							ansmat[i][j][1-curr]%=mod;
						}
					}
				}
				curr=1-curr;
			}
		}
		
				
		cout << "Case #" << ct << ":" << " " << ansmat[masktoi[((1<<k)-1)*(1<<(p-k))]][masktoi[((1<<k)-1)*(1<<(p-k))]][curr] << endl;
		fout << "Case #" << ct << ":" << " " << ansmat[masktoi[((1<<k)-1)*(1<<(p-k))]][masktoi[((1<<k)-1)*(1<<(p-k))]][curr] << endl;
		
		
	}

	
	return 0;
}

	