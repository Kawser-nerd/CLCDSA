#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int a[10001];
bool com(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	char s1[n][n+1];
	char s2[m][m+1];
	for(int i=0;i<n;i++)
	{
		cin>>s1[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>s2[i];
	}
	int flag;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s1[i][j]==s2[0][0])
			{
				for(int k=0;k<m;k++)
				{
					for(int l=0;l<m;l++)
					{
						if(s1[i+k][j+l]!=s2[k][l])
						{
							flag=0;
							break;
						}
						flag=1;
					}
					if(flag==0)
					break;
				}
			}
			if(flag==1)
			{
				cout<<"Yes";
				return 0;	
			}
		}
	}	
	cout<<"No";
	return 0;
}