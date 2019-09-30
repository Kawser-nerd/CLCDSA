#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	char a[4];
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}
	if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3] ){
		cout << "SAME" <<endl;
	}
	else{
		cout << "DIFFERENT" << endl;
	}

	return 0;

}