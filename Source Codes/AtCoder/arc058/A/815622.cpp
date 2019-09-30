#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

set<int> ds;

bool ok(int num){
	while(num){
		if(ds.count(num % 10)){
			return false;
		}
		num /= 10;
	}
	return true;
}

int main(){
	int n, k;
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int d;
		cin >> d;
		ds.insert(d);
	}
	for(int i=n;;i++){
		if(ok(i)){
			cout << i << endl;
			break;
		}
	}
	return 0;
}