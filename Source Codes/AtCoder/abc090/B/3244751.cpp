#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int a,b,c=0;cin>>a>>b;
	for(int i=a;i<=b;i++)
	{
		if(i/10000==i%10&&i/1000%10==i/10%10)
		{
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}