#include<iostream>
using namespace std;
const int maxn = 1e6+10;
int m,n;
int main()
{
	char c;
	int m=0;
	for(int i=1;i<=4;i++)
	{
		cin>>c;
		if(c=='+')m++;
		if(c=='-')m--;
	}
	cout<<m;
}