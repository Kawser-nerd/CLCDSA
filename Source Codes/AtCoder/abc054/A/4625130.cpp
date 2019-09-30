#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if((a&&b<=13)&&(a&&b>=1))
	{
	if(a==b)
	{
		cout<<"Draw";
	}
	
	else if(a==1)
	{
		cout<<"Alice";
	}
	else if(b==1)
	{
		cout<<"Bob";
	}

	else if (a>b)
	{
		cout<<"Alice";
	}
	else if(a<b)
	{
		cout<<"Bob";
	}
}
	return 0;
}