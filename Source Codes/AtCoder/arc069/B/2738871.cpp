#include <iostream>
#include <string>
using namespace std;

int n;
char s[100001] = {}, a[100001] = {}; // a -> animals; s -> answers
string ans;

bool solve(char x, char y){
	a[1] = x;
	a[2] = y;
	bool p, q;
	for(int i = 2; i <= n-1; i++)
		a[i] == 'S'?
			s[i] == 'o' ? a[i+1] = a[i-1] :
				a[i-1] == 'S' ? a[i+1] = 'W' : a[i+1] = 'S' :
			s[i] == 'x' ? a[i+1] = a[i-1] :
				a[i-1] == 'S' ? a[i+1] = 'W' : a[i+1] = 'S';
	p = a[n] == 'S' ?
		s[n] == 'o' ?
			a[n-1] == a[1] ? true : false : 
		a[n-1] != a[1] ? true : false : 
		// a[n] == 'W'
		s[n] == 'o' ?
			a[n-1] == a[1] ? false : true : 
		a[n-1] != a[1] ? false : true ;
	q = a[1] == 'S' ?
		s[1] == 'o' ?
			a[n] == a[2] ? true : false : 
		a[n] != a[2] ? true : false : 
		// a[n] == 'W'
		s[1] == 'o' ?
			a[n] == a[2] ? false : true : 
		a[n] != a[2] ? false : true ;
	return p && q;
}

int main() {
	cin >> n;
	for(int h = 1; h <= n; h++) a[h] = '_';
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	
	if(solve('S', 'S')){
		for(int k = 1; k <= n; k++) cout << a[k];
		cout << endl;
	} else if(solve('S', 'W')){
		for(int k = 1; k <= n; k++) cout << a[k];
		cout << endl;
	} else if(solve('W', 'S')){
		for(int k = 1; k <= n; k++) cout << a[k];
		cout << endl;
	} else if(solve('W', 'W')){
		for(int k = 1; k <= n; k++) cout << a[k];
		cout << endl;
	} else cout << "-1" << endl;
	
	return 0;
}