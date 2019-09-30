#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[3],k;
	cin >> a[0] >> a[1] >> a[2] >> k;
	int max=0,maxarr;
	for(int i=0;i<3;i++)
	{
		if(max <= a[i])
		{
			max = a[i];
			maxarr = i;
		}
	}
	int sum = 0;
	for(int j = 0;j<3;j++)
	{
		if(j == maxarr)
		{
			sum = sum + a[j]*pow(2,k);
		}
		
		else
		{
			sum = sum + a[j];
		}	
	}
	
	cout << sum;
	return 0;
}