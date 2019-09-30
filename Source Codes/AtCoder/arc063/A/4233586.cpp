#include <iostream>
using namespace std;
#define ll long long
#include <string>
#include <algorithm>
int main()
{
	string a;
	cin>>a;
	char c=a[0];
	int count=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=c)
		{
			c=a[i];
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}