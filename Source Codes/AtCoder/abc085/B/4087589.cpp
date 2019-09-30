#include<iostream>
using namespace std;

int t,s[105],num,res;
int main(){
	cin >> t;
	while(t--){
		cin >> num;	s[num]++;	if(s[num] == 1)	res++;
	}
	cout << res;
}