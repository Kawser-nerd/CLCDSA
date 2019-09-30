#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<set>
#include<iomanip>
using namespace std;

int main()
{
	int ans=1e7,n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int j=sqrt(i);
		for(;i%j!=0;j--);
		ans=min(ans,n-i+abs(j-i/j));
	}
	cout<<ans<<endl;
	return 0;
}