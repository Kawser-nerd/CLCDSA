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


double vals[200];

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
		int n,i,j,k;
		
		fin >> n;
		
		double d = 0.0;
		for(i=0; i<n; i++)
		{
			fin >> vals[i];
			d+=vals[i];
		}
		
		for(i=0; i<n; i++)
			vals[i]/=d;
		
		vector<double> ans;
		
		for(k=0; k<n; k++)
		{
			double mn = 0.0;
			double mx = 1.0;
			
			while(mx-mn > 1e-9)
			{
				double mid = (mx+mn)/2;
				
				double p = 0.0;
				
				for(i=0; i<n; i++)
				{
					if(i!=k)
					{
						double q = vals[k] + mid - vals[i];
						if(q>0)
							p+=q;
					}
				}
				
				if(p + mid >1.0)
				{
					mx= mid;
				}
				else {
					mn= mid;
				}
			}
			ans.push_back((mx+mn)*50.0);
		}

		
		
		cout << "Case #" << ct << ":";
		fout << "Case #" << ct << ":";
		
		for(k=0; k<n; k++)
		{
			fout << " " << ans[k];
			cout << "  "<< ans[k];
		}
		fout << endl;
		cout << endl;
		
	}
	
	
	return 0;
}

