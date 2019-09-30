#include<string>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int s,d;
cin>>s;
cin>>d;
cout<<(d-(s%d))%d<<endl;
return 0;
	}