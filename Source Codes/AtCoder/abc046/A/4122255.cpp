#include <iostream>
using namespace std;
bool f(int a,int b)
{
	if(a==b)
	{
		return true;
	}
	return false;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int count=0;
	if(f(a,b))
	{
		count++;
	}
	if(f(a,c))
	{
		count++;
	}
	if(f(b,c))
	{
		count++;
	}
	if(count==3)
	cout<<1;
	if(count==1)
	cout<<2;
	if(count==0)
	cout<<3;

	return 0;
 }