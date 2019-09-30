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
double xx[10000];
double yy[10000];
double zz[10000];
double p[10000];

int main(void)
{
	cout.precision(8);
	fout.precision(8);
	int ttt;
	cin >> ttt;
	int ct = 0;
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k,l;
		int n;
		cin >> n;
		for(i=0; i<n; i++)
		{	
			cin >> xx[i] >> yy[i] >> zz[i] >> p[i];
		}
		double mna,mnb,mnc,mnd,mxa,mxb,mxc,mxd;
		double mn,mx,md;
		mn=0;
		mx=1e7;
		double d,x,y,z;
		while(mx-mn>1e-7)
		{
			mna=mnb=mnc=mnd=-1e7;
			mxa=mxb=mxc=mxd=1e7;
			md=(mx+mn)/2;
			for(i=0; i<n; i++)
			{
				d = p[i]*md;
				x=xx[i];
				y=yy[i];
				z=zz[i];
				if(x+y+z+d<mxa)
				{
					mxa=x+y+z+d;
				}
				if(x+y+z-d>mna)
				{
					mna=x+y+z-d;
				}
				if(x+y-z+d<mxb)
				{
					mxb=x+y-z+d;
				}
				if(x+y-z-d>mnb)
				{
					mnb=x+y-z-d;
				}
				if(x-y+z+d<mxc)
				{
					mxc=x-y+z+d;
				}
				if(x-y+z-d>mnc)
				{
					mnc=x-y+z-d;
				}
				if(0-x+y+z+d<mxd)
				{
					mxd=0-x+y+z+d;
				}
				if(0-x+y+z-d>mnd)
				{
					mnd=0-x+y+z-d;
				}
			}
			//cout << mxa << " " << mxb << " " << mxc << " " << mxd << endl;
			//cout << mna << " " << mnb << " " << mnc << " " << mnd << endl;
			if(mxa-mna>1e-7 && mxb-mnb>1e-7 && mxc-mnc>1e-7 && mxd-mnd>1e-7)
			{
				mx=md;
			}
			else
			{
				mn=md;
			}
		}
		md=(mx+mn)/2.;
		cout << "Case #" << ct << ":" << " " << md << endl;
		fout << "Case #" << ct << ":" << " " << md << endl;
		
	}

	
	return 0;
}

