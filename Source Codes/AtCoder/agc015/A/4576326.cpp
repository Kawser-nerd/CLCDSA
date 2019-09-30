#include "iostream"

using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(n==1)
	{
		if(a==b)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	else 
	{
		if(a>b)
			cout<<0<<endl;
		else
			cout<<(long long)(b-a)*(n-2)+1<<endl;
	}
	system("pause");
}