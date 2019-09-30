#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	long long int a[90],n;
  	cin>>n;
	a[0]=2;a[1]=1;
	for(int i=1;i<n;i++)
	{
		a[i+1]=a[i]+a[i-1];
	}
	cout<<a[n]<<endl;
	return 0;
}