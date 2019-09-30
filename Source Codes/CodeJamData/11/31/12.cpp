#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>


using namespace std;

char buf[1000][1000];

bool range(int n, int m, int i, int j)
{
	return 0 <= i && i < n && 0 <= j && j < m;
}

bool refill(int n, int m)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (buf[i][j] == '#')
			{
				for (int di = 0; di <= 1; di++)
					for (int dj = 0; dj <= 1; dj++)
					{
						if (!range(n,m,i+di,j+dj))
							return false;
						if (buf[i+di][j+dj] != '#')
							return false;
						buf[i+di][j+dj] = (di ^ dj) ? '\\' : '/';
					}
			}
	return true;
}


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int t;
	cin>>t;
	for (int aaa = 0; aaa < t; aaa++)
	{

		int n,m;
		cin>>n>>m;
		for (int i=0;i<n;i++)
			cin>>buf[i];

		bool res = refill(n,m);

		cout<<"Case #"<<aaa + 1 <<":";
		cout<<endl;

		if (!res)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			for (int i=0;i<n;i++)
				cout<<buf[i]<<endl;
		}

	}

	
    return 0;
}