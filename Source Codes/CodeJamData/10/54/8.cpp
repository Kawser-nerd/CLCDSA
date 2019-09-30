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

ofstream fout("../../output.txt");
ifstream fin("../../input.txt");

long long ans[80][80][80][2];

long long mod  = 1000000007;

long long npr[80][80];

long long ways[6400][80];

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	fout.precision(19);
	cout.precision(19);
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k;
		memset(ans,0,sizeof(ans));
		for(i=0; i<80; i++)
		{
			for(j=0; j<80; j++)
			{
				if(j==0)
					npr[i][j]=1;
				else if(j>i)
					npr[i][j]=0;
				else {
					npr[i][j]=((long long)i)*npr[i-1][j-1];
					npr[i][j]%=mod;
				}
			}
		}
		
		long long n;
		long long b;
		fin >> n >> b;
		
		memset(ways, 0, sizeof(ways));
		
		ways[0][0]=1;
		
		for(k=1; k<b; k++)
		{
			for(i=b-1; i>0; i--)
			{
				for(j=k; j< b*b; j++)
				{
					if(ways[j-k][i-1]>0)
					{
						ways[j][i]+=ways[j-k][i-1];
						ways[j][i]%=mod;
					}
				}
			}
		}
		
		/*for(i=0; i<b; i++)
		{
			for(j=0; j<10; j++)
			{
				cout << ways[j][i] << " " ;
			}
			cout << endl;
		}*/
		
		
		ans[0][0][b][0]=1;
			long long currn = n;
		for(int psum= currn%b; psum<=b*b; psum+=b)
		{
			//cout << psum << endl;
			for(int digits=0; digits<b; digits++)
			{
				ans[1][(psum-(currn%b))/b][digits][0]+=ways[psum][digits];
				ans[1][(psum-(currn%b))/b][digits+1][1]+=ways[psum][digits];
				ans[1][(psum-(currn%b))/b][digits][0]%=mod;
				ans[1][(psum-(currn%b))/b][digits+1][1]%=mod;
				if(psum==6 && digits==1)
				{
					//cout << ans[1][(psum-(currn%b))/b][digits][0] << "**" << " " << (psum-(currn%b))/b <<  endl;
				}
			}
		}
		
		currn/=b;
		
		for(int x = 1; x<70; x++)
		{
			long long goal = currn%b;
			
			for(i=0; i<b; i++)
			{
				for(j=0; j<=b; j++)
				{
					if(ans[x][i][j][0]>0 || ans[x][i][j][1]>0)
					{
						//cout << x << " " << i << " " << j << " " << ans[x][i][j][0] << " " << ans[x][i][j][1] << endl;
						for(int psum = ((goal-i+b))%b; psum<b*b; psum+=b)
						{
							for(int digits = 0; digits<=j; digits++)
							{
								if(ways[psum][digits]>0)
								{
									ans[x+1][((i+psum)-goal)/b][digits][0]+=(((ans[x][i][j][0]*ways[psum][digits])%mod)*npr[j][digits])%mod;
									//if(j>=1)
									ans[x+1][((i+psum)-goal)/b][digits+1][1]+=((((ans[x][i][j][0]*ways[psum][digits])%mod)*npr[j][digits+1])%mod);
									if(j>=1)
									ans[x+1][((i+psum)-goal)/b][digits][0]+=(((ans[x][i][j][1]*ways[psum][digits])%mod)*npr[j-1][digits-1])%mod*((long long)digits);
									if(j>=1)
									ans[x+1][((i+psum)-goal)/b][digits+1][1]+=(((ans[x][i][j][1]*ways[psum][digits])%mod)*npr[j-1][digits])%mod*((long long)digits+1);
									ans[x+1][((i+psum)-goal)/b][digits][0]%=mod;
									ans[x+1][((i+psum)-goal)/b][digits+1][1]%=mod;
									
									/*if( x==0 && ((i+psum-goal)/b) ==0 && digits<=1)
									{
										cout << "* " << i << " " << j << " " << psum << " " << digits << endl;
									}*/
									
									//ans[x+1][((i+psum)-goal)/b][digits][0]%=mod;
									//ans[x+1][((i+psum)-goal)/b][digits][0]%=mod;
								}
							}
						}
					}
				}
			}
			
			currn/=b;
		}
		
		long long ret = ans[70][0][0][0];
		
		cout << "Case #" << ct << ": " << ret << endl;
		fout << "Case #" << ct << ": " << ret << endl;
		
	}
	
	
	return 0;
}



