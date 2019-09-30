#include<iostream>
using namespace std;

int main(){

	int a, b;
	cin >> a >> b;

	if( a==2 || b==2){
		cout << "No\n";
	}
	else if( a==4 || a==6 || a==9 || a==11){
		if( b==4 || b==6 || b==9 || b==11 ){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else{
		if( b==1 || b ==3 || b==5 || b ==7 || b==8 || b==10 || b==12){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;

}