#include <iostream>
#include <cmath>
using namespace std;
bool f(int a,int b)
{
	if(a==b)
	{
		return true;
	}
	return false;
}

int main()
{
	long long n,k;
	long long ci=1;
	cin>>n>>k;
	ci=pow(k-1,n-1);
	ci=ci*k;
	
	cout<<ci;
	return 0;
 }