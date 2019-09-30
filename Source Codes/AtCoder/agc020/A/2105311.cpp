#include<iostream>
using namespace std;

int main(){
	int N, A, B, D;
	cin >> N >> A >> B;
	D = B - A;
	if(D%2==0){
		cout << "Alice";
	}else{
		cout << "Borys";
	}	

	return 0;
}