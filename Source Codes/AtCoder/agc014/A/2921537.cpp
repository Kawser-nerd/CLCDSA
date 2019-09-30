#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long A,B,C;
	cin>>A>>B>>C;
	int sum;
	bool p=false;
	for(int i=0;i<=1000;i++)
	{
		if(A%2==1||B%2==1||C%2==1)
		{
			sum=i;
			p=true;
			break;
		}
		int A1,B1,C1;
		A1=A;
		B1=B;
		C1=C;
		A=B1/2+C1/2;
		B=A1/2+C1/2;
		C=A1/2+B1/2;
	}
	if(p==true)
		cout<<sum<<endl;
	else
		cout<<"-1"<<endl;	
}