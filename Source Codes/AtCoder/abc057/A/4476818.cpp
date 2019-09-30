#include <iostream>

using namespace std;

int main(){
 	int A,B,ans;
	cin >> A >> B;
	ans = (A+B) % 24;
	cout << ans << endl;
}