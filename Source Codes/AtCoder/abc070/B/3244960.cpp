#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int a,b,c,d,e=0;cin>>a>>b>>c>>d;
	for(int i=0;i<=100;i++)
	{
		if(a<=i&&i<=b&&c<=i&&i<=d)e++;
	}
	cout<<max(0,e-1)<<endl;
	return 0;
}