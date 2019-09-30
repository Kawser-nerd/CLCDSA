#include<iostream>
#include<algorithm>
using namespace std ;
int main()
{
	int n,x,a[105]  ; cin >> n >>x;
	for(int i=0;i<n;i++)
		cin >> a[i] ;
	sort(a,a+n) ;
	int m=0;
	while(x>=a[m]&&m<n-1) {x-=a[m] ;m++;}
	if(x==a[m]) m++;
	cout << m ;
	return 0 ;
}