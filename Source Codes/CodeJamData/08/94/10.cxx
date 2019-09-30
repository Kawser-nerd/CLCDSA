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

bool iscell[32][32];
bool isforest[32][32];

int fsq[900][2];

int mindists[32][32];
int minexcess[32][32];
int currmindists[32][32];

bool done[900];

int dolis[2500][2];

int px[4]={0,1,0,-1};
int py[4]={1,0,-1,0};

int m,n;

void updatemindists(int x, int y)
{
	int readfrom,writeto;
	readfrom=0;
	writeto=1;
	currmindists[x][y]=0;
	int i,j,k;
	dolis[0][0]=x;
	dolis[0][1]=y;
	while(readfrom<writeto)
	{
		i=dolis[readfrom][0];
		j=dolis[readfrom][1];
		for(k=0; k<4; k++)
		{
			if(iscell[i+px[k]][j+py[k]]&&currmindists[i+px[k]][j+py[k]]>currmindists[i][j]+1)
			{
				currmindists[i+px[k]][j+py[k]]=currmindists[i][j]+1;
				dolis[writeto][0]=i+px[k];
				dolis[writeto][1]=j+py[k];
				writeto++;
			}
		}
		readfrom++;
	}
	return;
}

void updateminexcess(int x, int y)
{
	int readfrom,writeto;
	readfrom=0;
	writeto=1;
	minexcess[x][y]=0;
	int i,j,k;
	dolis[0][0]=x;
	dolis[0][1]=y;
	while(readfrom<writeto)
	{
		i=dolis[readfrom][0];
		j=dolis[readfrom][1];
		for(k=0; k<4; k++)
		{
			if(iscell[i+px[k]][j+py[k]] && minexcess[i+px[k]][j+py[k]]>minexcess[i][j]+currmindists[i+px[k]][j+py[k]]-mindists[i+px[k]][j+py[k]])
			{
				minexcess[i+px[k]][j+py[k]]=minexcess[i][j]+currmindists[i+px[k]][j+py[k]]-mindists[i+px[k]][j+py[k]];
				dolis[writeto][0]=i+px[k];
				dolis[writeto][1]=j+py[k];
				writeto++;
			}
		}
		readfrom++;
	}
	return;
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
		int a,b;
		char c;
		int sofar = 0;
		cin >> n >> m;
		int nf = 0;
		memset(iscell,0,sizeof(iscell));
		memset(isforest,0,sizeof(isforest));
		memset(mindists,0,sizeof(mindists));
		memset(done,0,sizeof(done));
		memset(minexcess,0,sizeof(minexcess));
		memset(currmindists,0,sizeof(currmindists));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				cin >> c;
				if(c=='#')
				{
					iscell[i+1][j+1]=true;
				}
				else if(c=='T')
				{
					iscell[i+1][j+1]=true;
					isforest[i+1][j+1]=true;
					fsq[nf][0]=i+1;
					fsq[nf][1]=j+1;
					nf++;
				}
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				mindists[i][j]=10000;
				minexcess[i][j]=100000000;
				currmindists[i][j]=10000;
			}
		}
		
		int readfrom,writeto;
		readfrom=writeto=0;
		for(i=0; i<nf; i++)
		{
			mindists[fsq[i][0]][fsq[i][1]]=0;
			dolis[writeto][0]=fsq[i][0];
			dolis[writeto][1]=fsq[i][1];
			writeto++;
		}
		while(readfrom<writeto)
		{
			i=dolis[readfrom][0];
			j=dolis[readfrom][1];
			for(k=0; k<4; k++)
			{
				if(iscell[i+px[k]][j+py[k]]&&mindists[i+px[k]][j+py[k]]>mindists[i][j]+1)
				{
					mindists[i+px[k]][j+py[k]]=mindists[i][j]+1;
					dolis[writeto][0]=i+px[k];
					dolis[writeto][1]=j+py[k];
					writeto++;
				}
			}
			readfrom++;
		}
		
		/*for(i=1; i<=n; i++)
			{
				for(j=1; j<=m; j++)
				{
					cout <<	mindists[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;*/
		
		//got minimal distances
		
		updatemindists(1,1);
		sofar=1;
		done[0]=true;
		int ans =0;
		
		updateminexcess(1,1);
		for(k=1; k<nf; k++)
		{
			/*for(i=1; i<=n; i++)
			{
				for(j=1; j<=m; j++)
				{
					cout << minexcess[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=m; j++)
				{
					cout <<	currmindists[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;*/
			int best = 10000000;
			int bv = -1;
			for(j=0; j<nf; j++)
			{
				if(!done[j] && minexcess[fsq[j][0]][fsq[j][1]]<best)
				{
					best=minexcess[fsq[j][0]][fsq[j][1]];
					bv=j;
				}
			}
			j=bv;
			ans+=minexcess[fsq[j][0]][fsq[j][1]];
			updatemindists(fsq[j][0],fsq[j][1]);
			updateminexcess(fsq[j][0],fsq[j][1]);
			done[j]=true;
		}
		//cout << ans << endl;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				if(iscell[i][j])
					ans+=mindists[i][j];
			}
		}
		//cout << ans << endl;
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
		
	}

	
	return 0;
}

	