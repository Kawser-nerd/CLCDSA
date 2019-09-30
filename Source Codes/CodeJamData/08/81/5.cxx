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

double vxlis[2][3][2];
double area[2];

double matsolve[2][2];
double minv[2][2];
double matans[2];

// triangle, vx, x/y
int main(void)
{
	cout.precision(9);
	fout.precision(9);
	int ttt;
	cin >> ttt;
	int ct = 0;
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k,l;
		int m,a,b,c;
		for(l=0; l<2; l++)
		{
			for(i=0; i<3; i++)
			{
				for(j=0; j<2; j++)
				{
					cin >> vxlis[l][i][j];
				}
			}
		}
		double ax,ay,bx,by;
		double cx[2];
		double cy[2];
		double cc[2];
		memset(matsolve,0,sizeof(matsolve));
		matans[0]=matans[1]=0.0;
		for(int xx=0; xx<2; xx++)
		{
			int v1,v2,v3;
			v1=0;
			v2=1;
			v3=2;
			if(xx==1)
			{
				v2=2;
				v3=1;
			}
			
			for(i=0; i<2; i++)
			{
				ax=vxlis[i][v1][0]-vxlis[i][v2][0];
				ay=vxlis[i][v1][1]-vxlis[i][v2][1];
				cx[i]=0-ay;
				cy[i]=ax;
				cc[i]=ay*vxlis[i][v1][0]-ax*vxlis[i][v1][1];
				cout << cx[i] << " " << cy[i] << " " << cc[i] << endl;
			}
			for(i=0; i<2; i++)
			{
				area[i]=cx[i]*vxlis[i][v3][0]+cy[i]*vxlis[i][v3][1]+cc[i];
				cout << "AREA " << area[i] << endl;
			}
			matsolve[xx][0]+=area[1]*cx[0];
			matsolve[xx][0]-=area[0]*cx[1];
			matsolve[xx][1]+=area[1]*cy[0];
			matsolve[xx][1]-=area[0]*cy[1];
			matans[xx]-=area[1]*cc[0];
			matans[xx]+=area[0]*cc[1];
		}
		double disc = matsolve[0][0]*matsolve[1][1]-matsolve[0][1]*matsolve[1][0];
		bool state=true;
		if(disc<1e-9 && disc>-1e-9)
		{
			state=false;
			cout << "Case #" << ct << ":" << " " << vxlis[0][0][0] << " " << vxlis[0][0][1] << endl;
			fout << "Case #" << ct << ":" << " " << vxlis[0][0][0] << " " << vxlis[0][0][1] << endl;
			continue;
		}
		minv[0][0]=matsolve[1][1]/disc;
		minv[1][1]=matsolve[0][0]/disc;
		minv[0][1]=(0-matsolve[0][1])/disc;
		minv[1][0]=(0-matsolve[1][0])/disc;
		
			
		
		cout << "Case #" << ct << ":" << " " << minv[0][0]*matans[0]+minv[0][1]*matans[1] << " " << minv[1][0]*matans[0]+minv[1][1]*matans[1] << endl;
		fout << "Case #" << ct << ":" << " " << minv[0][0]*matans[0]+minv[0][1]*matans[1] << " " << minv[1][0]*matans[0]+minv[1][1]*matans[1] << endl;
		
		
	}

	
	return 0;
}

	