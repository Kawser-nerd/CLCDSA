#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<list>
using namespace std;
using ulong = unsigned long;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int>> wh(n);
	for(int i=0;i<n;i++){
		cin >> wh[i].first >> wh[i].second;
	}
	sort(wh.begin(), wh.end());
	// vector<double> v2;
	// int prev = -1;
	// for(int i=0;i<n;i++){
	// 	if(prev != wh[i].first){
	// 		v2.push_back(wh[i].second);
	// 	}
	// 	prev = wh[i].first;
	// }
	vector<double> dp(n, 1e9);
	// for(int i=0;i<v2.size();i++){
	// 	*lower_bound(dp.begin(), dp.end(), v2[i]) = v2[i];
	// }
	for(int i=0;i<wh.size();i++){
		vector<pair<int, int>> cands;
		// cout<<cands.size()<<endl;
		int end;
		for(end = i; end < wh.size(); end++){
			if(wh[i].first != wh[end].first){ break; }
			cands.push_back(wh[end]);
		}
		i = end - 1;
		vector<decltype(dp.begin())> dests;
		for(int j=0;j<cands.size();j++){
			dests.push_back(lower_bound(dp.begin(), dp.end(), cands[j].second));
		}
		for(int j=cands.size()-1;j>=0;j--){
			*dests[j] = cands[j].second;
		}
	}
	cout << lower_bound(dp.begin(), dp.end(), 1e9) - dp.begin() << endl;
	return 0;
}