#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int a,b;
	char s[20];
	cin>>a>>b>>s;
	for(int i=0;i<=a+b;i++)
	{
		if(i==a)
		{
			if(s[i]!='-')
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
		else
		{
			if(s[i]=='-')
			{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}