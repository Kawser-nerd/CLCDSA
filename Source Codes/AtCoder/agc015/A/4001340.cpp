#include<iostream>
#include<cmath>
#include<cstring>
typedef long long LL;
using namespace std;

bool is_ok(LL N,LL A,LL B){
	if(N == 1 && A == B)
		return true;
	else if(N > 1 && A <= B)
		return true;
	return false;
}


int main(){
	LL N,A,B;
	cin >> N >> A >> B;
	
	if(is_ok(N,A,B)){
		if(N == 1 || A == B)
			cout << 1 << endl;
		else{
			LL diff = B-A;
			cout << diff*(N-2)+1 << endl;
		}
			
	}
	else
		cout << 0 << endl;
	return 0;
}