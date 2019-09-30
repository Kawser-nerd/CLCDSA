#include <iostream>
using namespace std;

int gcd(int a,int b) {
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main() {
	int n,k;
	cin>>n>>k;
	int t1,t2,mmax;
	cin>>t1; mmax=t1;
	if (n == 1)
		cout<<( (t1==k)?"POSSIBLE":"IMPOSSIBLE" )<<endl;
	else {
		while (--n>0) {
			cin>>t2; mmax=mmax>t2?mmax:t2;
			t1 = gcd(t1,t2);
		}
		cout<<( (k%t1==0&&k<=mmax)?"POSSIBLE":"IMPOSSIBLE" )<<endl;
	}
	return 0;
}