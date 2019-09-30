#include <iostream>
using namespace std;
int main()
{
	char a,b;
	cin>>a>>b;
	if(a=='H')
	{
		if(b=='H')
		{
			cout<<"H";
		}
		else
		{
			cout<<"D";
		}
	}
	else
	{
		if(b=='D')
		{
			cout<<"H";
		}
		else
		{
			cout<<"D";
		}
	}
	return 0;
}