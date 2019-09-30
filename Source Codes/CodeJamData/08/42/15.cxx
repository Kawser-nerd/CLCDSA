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

int main(void)
{
	int ttt;
	cin >> ttt;
	int ct = 0;
	while(ttt>0)
	{
		ct++;
		ttt--;
		int a,b,c,d,x,y;
		int i,j,k,l;
		int ansx,ansy,ansa,ansb;
		bool done=false;
		int N,M,A;
		cin >> N >> M >> A;
		for(x=0; x<=N; x++)
		{
			for(y=0; y<=M; y++)
			{
				for(a=0; a<=N; a++)
				{
					for(b=0; b<=M; b++)
					{
						i=b*x+a*y-x*y;
						if(i==A || i==0-A)
						{
							done=true;
							ansx=x;
							ansy=y;
							ansa=a;
							ansb=b;
						}
					}
				}
			}
		}
		
		cout << "Case #" << ct << ":" << " ";
		fout << "Case #" << ct << ":" << " ";
		if(done)
		{
			cout << ansx << " 0 0 " << ansy << " " << ansa << " " << ansb << endl;
			fout << ansx << " 0 0 " << ansy << " " << ansa << " " << ansb << endl;
		}
		else
		{
			cout << "IMPOSSIBLE" << endl;
			fout << "IMPOSSIBLE" << endl;
		}
		
	}

	
	return 0;
}

