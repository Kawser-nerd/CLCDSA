#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(void){
	string a,b;
	cin >> a; 
	cin >> b;
	int i = 0, j = 0;
	while(true){
		if(i == a.length()){
			break;
		}else{
			cout << a[i++];
		}
		if(j == b.length()){
			break;
		}else{
			cout << b[j++];
		}
	}
	cout << endl;
	return 0;
}