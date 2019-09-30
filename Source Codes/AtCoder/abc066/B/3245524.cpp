#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	string s;
	cin>>s;
	for(int i=s.size()-2;;i-=2)
	{
		for(int j=0;j<i/2;j++)
		{
			if(s[j]!=s[j+i/2])break;
			if(j==i/2-1)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}