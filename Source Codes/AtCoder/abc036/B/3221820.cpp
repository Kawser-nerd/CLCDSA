#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;
int main()
{
	char a[51][51];
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[n-j-1][i];
		}
		cout<<endl;
	}
	return 0;
}