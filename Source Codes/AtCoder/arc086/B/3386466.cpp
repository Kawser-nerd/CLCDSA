#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<pair<int,int>> op;
int n;

void print(){
	for(int i = 1; i <= n; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	int mabs = 0, mi = 0, count = 0;;
	cin >> n;
	a.resize(n+2);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(mabs <= abs(a[i])){
			mabs = abs(a[i]);
			mi = i;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(i == mi) continue;
		a[i] += a[mi];
		//cout << mi << " " << i << endl;
		count++;
		op.push_back(make_pair(mi,i));
	}
	//print();
	if(a[mi] >= 0){
		for(int i = 1; i <= n - 1; ++i){
			if(a[i] > a[i+1]){
				a[i+1] += a[i];
				//cout << i << " " << i+1 << endl;
				count++;
				op.push_back(make_pair(i,i+1));
			}
		}
	}else{
		for(int i = n - 1; i >= 1; --i){
			if(a[i] > a[i+1]){
				a[i] += a[i+1];
				//cout << i+1 << " " << i << endl;
				count++;
				op.push_back(make_pair(i+1, i));
			}
		}
	}
	//print();
	cout << count << endl;
	for(auto x : op){
		cout << x.first << " " << x.second << endl;
	}
	return 0;
}