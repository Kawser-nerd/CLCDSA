#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string s;
	long long k;
	cin>>s>>k;
	for(int i=0;i<s.size();i++) if(s[i]!='1') 
	{
		if(k<=i)
		{
			cout<<"1";
			return 0;
		}
		cout<<s[i];
		return 0;
	}
	cout<<"1";
	return 0;
}