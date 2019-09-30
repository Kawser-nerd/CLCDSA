#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int a,b,k;cin>>a>>b>>k;
	for(int i=a;i<=b;i++)
	{
		if(i<a+k||b-k<i)
		{
			cout<<i<<endl;
		}
	}
	return 0;
}