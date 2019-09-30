#include <iostream>
#include <algorithm>
using namespace std ;
bool cmp(int a ,int b)
{
	return a < b ;
}
int main()
{
	int N;
	int a[200];
	int c[200];
	cin>>N;
	for(int i=0;i<2*N;i++)
        {
                cin>>a[i];
        }
	sort(a,a+(2*N),cmp);
	for(int i=0;i<2*N;i++)
	{
		c[i]=a[i];
	}

	int sum=0;
        for(int z=0;z<2*N;z=z+2)
        {
                sum=c[z]+sum;
        }
	cout<<sum;
	return 0 ;
}