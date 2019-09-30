#include<iostream>
#include<algorithm>
using namespace std;
int n,a[110000],b[110000];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	int ans1=0,ans2=0;
	for(int i=1;i<n;i++)
		if(a[i]==i)swap(a[i],a[i+1]),ans1++;
	for(int i=n;i>1;i--)
		if(b[i]==i)swap(b[i],b[i-1]),ans2++;
	if(a[n]==n)swap(a[n-1],a[n]),ans1++;
	if(b[1]==1)swap(b[1],b[2]),ans2++;
	cout<<min(ans1,ans2)<<endl;
}