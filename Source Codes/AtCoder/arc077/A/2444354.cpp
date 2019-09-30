#include <iostream>
#include <list>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool p = true; // odd = true, even = false
	list<long long> a;
	long long m;
	for(int i = 0; i < n; i++){
		cin >> m;
		i % 2 ? a.push_back(m) : a.push_front(m);
	}
	if(n % 2) a.reverse();
	
	while(n--){
		cout << a.back() << ' ';
		a.pop_back();
	}
	
	return 0;
}