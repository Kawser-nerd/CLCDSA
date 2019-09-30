#include <iostream>
#include <vector>

using namespace std;

const long long INF = (1LL << 60);

struct Edge {
	Edge(int d, int c) : dst(d), cost(c) {}
	int dst;
	int cost;
};

struct Data {
	Data(long long a, long long b){ val[0] = a; val[1] = b; }
	long long val[2];
	void add(int v){ for(int i=0;i<2;i++) val[i] += v; }
	bool operator < (const Data& d) const {
		if(val[0] < d.val[0]) return true;
		return val[0] == d.val[0] && val[1] < d.val[1];
	}
};

void search(vector<Data>& res, const vector<vector<Edge>>& g, int pos, long long upper){
	res.clear();
	if(g[pos].size() == 0){
		res.emplace_back(Data(0, 0));
		return;
	}
	vector<Data> data[2];
	for(int i=0;i<2;i++){
		search(data[i], g, g[pos][i].dst, upper);
		if(data[i].empty()) return;
		for(int j=0;j<data[i].size();j++){
			data[i][j].add(g[pos][i].cost);
		}
	}
	if(data[1].size() < data[0].size()) swap(data[0], data[1]);
	int idx0[2] = {0, (int)data[0].size()-1};
	int idx1[2][2] = {{0, (int)data[1].size()-1}, {0, (int)data[1].size()-1}};
	while(idx0[0] < data[0].size() || idx0[1] >= 0){
		int check = 0;
		if(idx0[0] == data[0].size()){
			check = 1;
		} else if(idx0[1] == -1){
			check = 0;
		} else {
			check = (data[0][idx0[0]].val[0] < data[0][idx0[1]].val[1] ? 0 : 1);
		}
		const auto baseVal = data[0][idx0[check]].val[1-check];
		long long minVal = INF;
		for(int i=0;i<2;++i){
			while(0 <= idx1[check][i] && idx1[check][i] < data[1].size() && baseVal + data[1][idx1[check][i]].val[i] <= upper){
				minVal = min(minVal, data[1][idx1[check][i]].val[1-i]);
				idx1[check][i] += 1 - 2*i;
			}
		}
		if(minVal < INF){
			Data d(data[0][idx0[check]].val[check], minVal);
			if(res.empty() || (res.back().val[0] < d.val[0] && res.back().val[1] > d.val[1])){
				res.push_back(d);
			} else if(d < res.back()){
				res.back() = d;
			}
		}
		idx0[check] += 1 - 2*check;
	}
	return;
}

int main(){
	int N;
	while(cin >> N){
		vector<vector<Edge>> g(N);
		for(int i=0;i<N-1;i++){
			int d, c; cin >> d >> c;
			g[d-1].emplace_back(Edge(i+1, c));
		}
		long long low = -1, high = 1LL << 35;
		vector<Data> vd;
		while(high - low > 1){
			long long mid = (low+high)/2;
			search(vd, g, 0, mid);
			if(!vd.empty()){
				high = mid;
			} else {
				low = mid;
			}
		}
		cout << high << endl;
	}
}