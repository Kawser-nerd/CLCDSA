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

struct Node{
	vector<Node*> nodes;
	int solve(int k){
		int ret = solveV(0, k, nullptr);
		for(Node* n : nodes){
			ret = min(ret, n -> solveV(1, k, this) + solveV(1, k, n));
		}
		return ret;
	}
	int solveV(int len2 , int k, Node* from){
		int cnt = 0;
		if(len2 > k){
			cnt++;
		}
		for(Node* n : nodes) if(n != from){
			cnt += n -> solveV(len2 + 2, k, this);
		}
		// cout<<cnt<<endl;
		return cnt;
	}
};

int main(){
	int n, k;
	cin >> n >> k;
	vector<Node> nodes(n);
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		nodes[a].nodes.push_back(&nodes[b]);
		nodes[b].nodes.push_back(&nodes[a]);
	}
	int ans = 1e9;
	for(Node& n : nodes){
		ans = min(ans, n.solve(k));
		// cout<<ans<<endl;
	}
	cout << ans << endl;
	return 0;
}