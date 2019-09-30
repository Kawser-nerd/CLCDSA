#include <iostream>
#include "string.h"

using namespace std;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string A,B;
	cin >> A;
	cin >> B;
	int lenA = A.length();
	int lenB = B.length();
	bool flag = true;
	if(lenA > lenB){
		cout << "GREATER" << endl;
		flag = false;
	}
	else if (lenA < lenB){
		cout << "LESS" << endl;
		flag = false;
	}else{
		for(int i = 0;i < lenA;i++){
			//int charA = ((int)(unsigned char) A[i]);
			int charA = (int)A[i];
			int charB = (int)B[i];
			if(charA > charB){
				cout << "GREATER" << endl;
				flag = false;
				break;
			}else if(charA < charB){
				cout << "LESS" << endl;
				flag = false;
				break;
			}
		}
	}
	if(flag) cout << "EQUAL" << endl;
	
	return 0;
}