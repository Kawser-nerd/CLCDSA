#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int tmp=0;
	vector<int> left(n+1);

	for(int i=0; i<left.size(); i++) left[i] = m - (4*i);
	for(int i=0; i<left.size(); i++){
		if(left[i] < 0) break;
		//3*2 = 4 + 1
		if(2*(n-i) == left[i]){
			cout << n-i << " 0 " << i << endl;
			return 0;
		}		
		if(n-i-1 >= 0 && 2*(n-i-1) + 3 == left[i]){
			cout << n-i-1 << " 1 " << i << endl;
			return 0;
		}
		/*
		for(int j=0; j<=n-i; j++){
			if(left[i] == (2*j + 3*((n-i)-j))) {
				//cout << i << "=" <<2*j + 3*((n-i)-j) << endl;
				cout << j << " " << (n-i)-j << " "<< i;
				return 0;
			}
		}*/
	}

	cout << "-1 -1 -1" << endl;
	//for(int i: left) cout << i << endl;
}