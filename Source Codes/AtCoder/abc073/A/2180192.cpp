#include<iostream>
using namespace std;
 
int main(){
 
	char a[2];
 
	cin >> a[0] >> a[1];
 
	if (a[0]=='9'){
		cout << "Yes";
	}
	else if(a[1]=='9'){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
 
 
 
	return 0;
}