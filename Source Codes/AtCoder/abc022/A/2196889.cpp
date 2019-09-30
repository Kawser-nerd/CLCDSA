#include<iostream>
#include <string>
#include<vector>

using namespace std;

int main(){

	int n, s, t, w;
	int count =0;
	cin >> n >> s >> t >> w;
	int a[n-1];
	for(int i = 0; i < n-1; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		if(s<=w && w<=t){
			count++;
		}
		w = w+a[i];
	}
	cout << count << endl;

	return 0;

}