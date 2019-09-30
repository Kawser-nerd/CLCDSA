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
#include <queue>

using namespace std;

ofstream fout("../../output.txt");
ifstream fin("../../input.txt");


int f[100][100];
int c[100][100];

bool seen[100][100];

int mx = 1000000000;

int px[4]={0,1,0,-1};
int py[4]={1,0,-1,0};

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int n,i,j,k,m;
		
		
		int h;
		
		fin >> h >> n >> m;
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				fin >> c[i][j];
				seen[i][j]=false;
			}
		}
		
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				fin >> f[i][j];
				seen[i][j]=false;
			}
		}
		
		
		
		
		
		priority_queue<pair<int,int> > lis;
		
		lis.push(make_pair(mx,0));
		
		double ans = 0.0;
		
		while(lis.size()>0)
		{
			pair<int,int> curr = lis.top();
			lis.pop();
			
			int currt = mx- curr.first;
			
			int currx = curr.second/100;
			int curry = curr.second%100;
			
			if(currx==n-1 & curry==m-1)
			{
				ans=((double)currt)/10.;
				break;
			}
			
			if(seen[currx][curry])
				continue;
			seen[currx][curry]=true;
			
			for(i=0; i<4; i++)
			{
				int nx = currx + px[i];
				int ny = curry + py[i];
				
				if(nx >=n || nx<0 || ny>=m || ny<0)
					continue;
				
				bool isok = true;
				
				if(f[currx][curry]+50>c[nx][ny])
					continue;
				if(f[nx][ny]+50>c[nx][ny])
					continue;
				if(f[nx][ny]+50>c[currx][curry])
					continue;
				
				int waterlevelneeded = c[nx][ny]-50;
				
				int besttime = 0;
				
				if(waterlevelneeded>=h)
					;
				else {
					besttime = h - waterlevelneeded;
				}
				
				if(besttime < currt)
					besttime=currt;
				
				if(besttime==0)
				{
					lis.push(make_pair(mx,nx*100+ny));
					continue;
				}
				
				int currh = h - besttime;
				if(currh - f[currx][curry]>=20)
				{
					lis.push(make_pair(mx-besttime-10,nx*100+ny));
				}
				else
				{
					lis.push(make_pair(mx-besttime-100,nx*100+ny));
				}
				

				
			}
			
		}
		
		
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
	}
	
	
	return 0;
}

