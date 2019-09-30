#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	if(n>=100&&n<=999)
	{
		if(n%10==n/100)
		  cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		
	}
}