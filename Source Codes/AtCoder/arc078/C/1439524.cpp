#include<iostream>
using namespace std;
long long c[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
char s[100];
bool query(long long n)
{
	cout<<"? "<<n<<endl;
	cin>>s;
	return s[0]=='Y';
}
int main()
{
	if(query(c[9]))for(int i=9;;i--)
		if(!i||!query(c[i]-1))
		{
			cout<<"! "<<c[i]<<endl;
			return 0;
		}
	for(int i=8;;i--)
		if(query(c[i]))
		{
			long long l=c[i],r=c[i+1];
			while(l+1<r)
			{
				long long m=(l+r)>>1;
				if(query(m*10))r=m;
				else l=m;
			}
			cout<<"! "<<r<<endl;
			return 0;
		}
}