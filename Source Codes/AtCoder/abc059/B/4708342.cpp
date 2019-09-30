#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){

	string A, B;
	cin >> A >> B;

	int i;

	if(A.size() > B.size()){
		cout << "GREATER\n";
		return 0;
	}else if (A.size() < B.size()){
		cout << "LESS\n";
	}else {
		for(i = 0; i < A.size(); i++){
			
			if(A[i] > B[i]){
				cout << "GREATER\n";
				return 0;
			}else if(A[i] < B[i]){
				cout << "LESS\n";
				return 0;
			}

		}	
		cout << "EQUAL\n";
                return 0;

	}


}