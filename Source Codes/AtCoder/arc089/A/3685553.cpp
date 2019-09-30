#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int t,x,y;
}a[100010];
int main()
{
	int n,i;
	cin >> n;
	a[0].x=0;a[0].y=0;a[0].t=0;
	for(i=1;i<=n;i++)
		cin >> a[i].t>>a[i].x>>a[i].y;
	for(i=1;i<=n;i++){
		int minn=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
		int realt=a[i].t-a[i-1].t;
		if(minn%2!=realt%2||realt<minn) break;
	}
	if(i>n) cout << "Yes"<<endl;
	else cout <<"No"<<endl; 
	return 0;
}