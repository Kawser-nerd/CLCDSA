#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005],sum[100005];
int main(){
	int n,i;
	long long cont;
	while(cin>>n){
		cont=0;
	 for (i=0;i<n;i++)
	 cin>>a[i];
	 sort(a,a+n);
	 sum[0]=a[0];
	 for (i=1;i<n;i++)
	 sum[i]=sum[i-1]+a[i];
	 for (i=n;i>0;i--)
	 if (a[i]<=sum[i-1]*2)
	 cont++;
	 else
	 break;
	 cout<<cont<<endl;
	}
	return 0;
}