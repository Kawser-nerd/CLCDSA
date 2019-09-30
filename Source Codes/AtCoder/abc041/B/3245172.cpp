#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	long long int a,b,c,d;
	cin>>a>>b>>c;d=1e9+7;
  	a%=d;b%=d;c%=d;
	a=a*b%d;
	cout<<a*c%d<<endl;
	return 0;
}