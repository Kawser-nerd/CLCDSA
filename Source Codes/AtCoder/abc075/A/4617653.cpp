#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a&&b&&c>=-100)&&(a&&b&&c<=100))
	{
	if (a==b)
	{
		cout<<c;
	}
	else if(a==c)
	{
		cout<<b;
	}
	else if(b==c)
	{
		cout<<a;
	}
}
return 0;
}