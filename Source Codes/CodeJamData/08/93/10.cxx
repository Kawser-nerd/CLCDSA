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

int tots[50];
int vals[50];

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
		int r;
		cin >> r >> c;
		
		memset(vals,0,sizeof(vals));
		memset(tots,0,sizeof(tots));
		
		for(i=0; i<r; i++)
		{
			j=0;
			for(k=0; k<c; k++)
			{
				cin >> l;
				j+=l;
			}
			tots[i]=j;
		}
		int n = r;
		
		int ans = 0;
		if(n==3)
		{
			ans=tots[0]+tots[2]-tots[1];
		}
		else
		{
			vals[2] = tots[1]-tots[0];
			for(i=5; i<n; i+=3)
			{
				vals[i]=(tots[i-1]-tots[i-2]+vals[i-3]);
			}
			vals[n-3]=tots[n-2]-tots[n-1];
			for(i=n-6; i>=0; i-=3)
			{
				vals[i]=(tots[i+1]-tots[i+2]+vals[i+3]);
			}
			if( ((n+1)%3)==0)
			{
				ans=vals[(n-1)/2];
			}
			else
			{
				ans=tots[(n-1)/2]-vals[(n-1)/2+1]-vals[(n-1)/2-1];
			}
			
		}
		for(i=0; i<11; i++)
		{
			cout << vals[i] << " ";
		}
		cout << endl;
		if(ans%3>0)
		{
			ans+=(3-(ans%3));
			
		}
		ans/=3;
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
		
	}

	
	return 0;
}

	