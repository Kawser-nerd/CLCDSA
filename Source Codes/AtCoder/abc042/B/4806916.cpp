#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,l;
	while(cin>>n>>l)
	{
		string str[105];
		for(int i=0;i<n;i++)
		  cin>>str[i];

		sort(str,str+n);

		for(int j=0;j<n;j++)
		 cout<<str[j];

		 cout<<endl;
	}
	return 0;
}