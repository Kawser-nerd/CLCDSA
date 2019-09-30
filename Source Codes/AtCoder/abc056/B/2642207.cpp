#include <iostream>
using namespace std;

int main() {
	int w,a,b;
	cin>>w>>a>>b;
	if (b>=a+w){
	cout<<abs(a+w-b);}
	else if ((b>=a)) cout<<0;
	else cout<<abs(b+w-a);
	return 0;
}