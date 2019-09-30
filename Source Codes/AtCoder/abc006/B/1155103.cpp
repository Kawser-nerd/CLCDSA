#include<iostream>
#include<vector>
using namespace std;
/*
const int INF = -999999;
vector<int> tri(1000001, INF);
int trib(int n){
	if(n == 1) return 0;
	if(n == 2) return 0;
	if(n == 3) return 1;
	if(tri[n] != INF) return tri[n];
	return tri[n] = (trib(n-1) + trib(n-2) + trib(n-3))%10007;
}
*/		

int main(){
	int n;
	cin >> n;
	vector<int> v(n+1);
	
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 1;
	for(int i=4; i<v.size(); i++){
		v[i] = (v[i-1] + v[i-2] + v[i-3])%10007;
	}

	cout << v[n] << endl;
	//cout << trib(n) << endl;
}