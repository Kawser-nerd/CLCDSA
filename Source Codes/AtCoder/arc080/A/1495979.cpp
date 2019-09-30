#include <iostream>
using namespace std;

int n,a[100010],sum1,sum2,cnt1,cnt2;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]%4==0) sum1++;
		if(a[i]%4==1||a[i]%4==3) sum2++;
		if(a[i]%4==2) cnt1++;
		if(a[i]==2) cnt2++;
		
	}
	sum1+=cnt2/2;
	if(sum1+1>=sum2+min(1,cnt1)) cout<<"Yes"; else cout<<"No";
	
	return 0;
}