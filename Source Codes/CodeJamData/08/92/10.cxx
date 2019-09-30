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

bool done[100][100];

int dolis[10000][2];

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
		int ax,ay,bx,by;
		int n;
		cin >> n;
		cin >> m;
		int sx,sy;
		cin >> ax >> ay >> bx >> by >> sx >> sy;
		int readfrom=0;
		int writeto=1;
		memset(done,0,sizeof(done));
		dolis[0][0]=sx;
		dolis[0][1]=sy;
		done[sx][sy]=true;
		while(readfrom<writeto)
		{
			i=dolis[readfrom][0];
			j=dolis[readfrom][1];
			
			k=i+ax;
			l=j+ay;
			if(0<=k && k<n && 0<=l && l<m && !done[k][l])
			{
				done[k][l]=true;
				dolis[writeto][0]=k;
				dolis[writeto][1]=l;
				writeto++;
			}
			k=i+bx;
			l=j+by;
			if(0<=k && k<n && 0<=l && l<m && !done[k][l])
			{
				done[k][l]=true;
				dolis[writeto][0]=k;
				dolis[writeto][1]=l;
				writeto++;
			}
			readfrom++;
		}
		
		cout << "Case #" << ct << ":" << " " << readfrom << endl;
		fout << "Case #" << ct << ":" << " " << readfrom << endl;
		
		
	}

	
	return 0;
}

	