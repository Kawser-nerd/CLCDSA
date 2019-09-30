#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;

map<int, set<int>> table;
map<pair<int, int>, int> ans;
int h, w, n;

void add(int t, int l){
	if(l < 1 || t < 1 || l + 2 > w || t + 2 > h){ return; }
	int cnt = 0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(table.count(t + i) && table[t + i].count(l + j)){
				cnt++;
			}
		}
	}
	ans[{l, t}] = cnt;
	// cout<<l<<' '<<t<<' '<<cnt<<endl;
}

int main(){
	cin >> h >> w >> n;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		table[a].insert(b);
	}
	for(auto p : table){
		int a = p.first;
		for(auto b : p.second){
			// cout<<a<<' '<<b<<endl;
			add(a-2, b-2);
			add(a-2, b-1);
			add(a-2, b);
			add(a-1, b-2);
			add(a-1, b-1);
			add(a-1, b);
			add(a, b-2);
			add(a, b-1);
			add(a, b);
		}
	}
	
	vector<ll> ansv(10);
	for(auto p : ans){
		ansv[p.second]++;
	}
	// cout<<ansv[0]<<endl;
	ansv[0] = 1ll * (h - 2) * (w - 2) - accumulate(ansv.begin(), ansv.end(), 0);
	for(int i=0;i<10;i++){
		cout << ansv[i] << endl;
	}
	return 0;
}