#include<iostream>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	for(int i=1;i<=100000;i++)
	{
		if((a*i)%b==c%b)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}