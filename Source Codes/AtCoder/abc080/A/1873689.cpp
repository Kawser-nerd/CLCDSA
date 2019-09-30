#include <iostream>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if(a*n<=b)
		cout<<a*n<<endl;
	else 
		cout<<b<<endl;
	return 0;
}