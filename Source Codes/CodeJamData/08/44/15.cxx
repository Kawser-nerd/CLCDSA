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
string s;

int numeq[16][16];
int plus1eq[16][16];
int anses[1<<16][16];

int main(void)
{
	int ttt;
	cin >> ttt;
	int ct = 0;
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k,l,a,b;
		int n;
		cin >> k;
		cin >> s;
		int m;
		n=s.size();
		m=n/k;
		memset(numeq,0,sizeof(numeq));
		memset(plus1eq,0,sizeof(plus1eq));
		for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				if(i<j)
				{
					for(l=0; l<m; l++)
					{
						if(s[i+l*k]==s[j+l*k])
						{
							numeq[i][j]++;
							numeq[j][i]++;
						}
					}
				}
				for(l=0; l<m-1; l++)
				{
					if(s[i+l*k]==s[j+l*k+k])
					{
						plus1eq[i][j]++;
					}
				}
			}
		}
		/*for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				cout << numeq[i][j] << " ";
			}
			cout << endl;
		}
		for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				cout << plus1eq[i][j] << " ";
			}
			cout << endl;
		}*/
		int ans = n;
		for(int st=0; st<k; st++)
		{
			//cout << "SS " << st << endl;
			memset(anses,0,sizeof(anses));
			for(i=0; i<(1<<k); i++)
			{
				if((i&(1<<st))==0)
				{
					continue;
				}
				for(j=0; j<k; j++)
				{
					if((1<<j)&i)
					{
						//cout << i << " " << j << " " << anses[i][j] << endl;
						for(l=0; l<k; l++)
						{
							if((1<<l)&i)
							{
								continue;
							}
							if( 1+i+(1<<l)==(1<<k))
							{
								a=anses[i][j]+numeq[j][l]+plus1eq[l][st];
								if(a>anses[i+(1<<l)][l])
								{
									anses[i+(1<<l)][l]=a;
								}
							}
							else
							{
								a=anses[i][j]+numeq[j][l];
								if(a>anses[i+(1<<l)][l])
								{
									anses[i+(1<<l)][l]=a;
								}
							}
						}
					}
				}
			}
			//cout << ans << endl;
			for(i=0; i<k; i++)
			{
				if(n-anses[(1<<k)-1][i]<ans)
				{
					ans=n-anses[(1<<k)-1][i];
				}
			}
			//cout << ans << endl;
		}
		
		
		cout << "Case #" << ct << ":" << " " << ans << endl;
		fout << "Case #" << ct << ":" << " " << ans << endl;
		
	}

	
	return 0;
}

