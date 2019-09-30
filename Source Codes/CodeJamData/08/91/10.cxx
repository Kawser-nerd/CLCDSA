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

int a[5000];
int b[5000];
int c[5000];

int vals[10002];

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
		int m;
		int n;
		cin >> n;
		for(i=0; i<n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			
		}
		int ans =0;
		for(i=0; i<=10000; i++)
		{
			memset(vals,0,sizeof(vals));
			for(j=0; j<n; j++)
			{
				if(i>=a[j])
				{
					k=b[j];
					l=10000-i-c[j];
					if(k<=l)
					{
						vals[k]++;
						vals[l+1]--;
					}
				}
			}
			k=0;
			for(j=0; j<=10000; j++)
			{
				k+=vals[j];
				if(k>ans)
				{
					ans=k;
					//cout << ans << " " << i <<" " << j << endl;
				}
			}
		}
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
		
	}

	
	return 0;
}

	