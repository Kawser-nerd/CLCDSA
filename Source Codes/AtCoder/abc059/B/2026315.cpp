#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	if (a.size()>b.size())
		cout<<"GREATER"<<endl;
	else if (b.size()>a.size())
		cout<<"LESS"<<endl;
	else
	{
		long long i;
		for(i=0;i<a.size();i++)
		{
			if (a[i]>b[i])
			{
				cout<<"GREATER"<<endl;
				break;
			}
			else if (a[i]<b[i])
			{
				cout<<"LESS"<<endl;
				break;
			}
		}
		if(i==a.size())
			cout<< "EQUAL" <<endl;
	}
	return 0;	
}