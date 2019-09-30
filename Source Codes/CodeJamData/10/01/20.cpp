#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n,k;

int main()
{
	cin>>t;
	for (int caseI=1;caseI<=t;caseI++)
	{
		cin>>n>>k;
		k++;
		cout<<"Case #"<<caseI<<": ";
		if ((k&((1<<n)-1)))
			cout<<"OFF"<<endl;
		else
			cout<<"ON"<<endl;
	}
	return 0;
}

