#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	long a[10000],b[10000],n,i,j,ans,test,numtest;
	
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> numtest;
	for(test=1;test<=numtest;test++)
	{
		cin >> n;
		for(i=1;i<=n;i++) cin >> a[i] >> b[i];
		ans=0;
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++) if(a[i]<a[j]&&b[i]>b[j]||a[i]>a[j]&&b[i]<b[j]) ans++;
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
	return 0;
}
