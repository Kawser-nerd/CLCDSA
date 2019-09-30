#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ulong = unsigned long;
using ll = long long;

struct Vert;
struct Edge{
	int type;
	Vert* dest;
	Edge(int type, Vert* dest): type(type), dest(dest){}
};
struct Vert{
	vector<Edge> edges;
	int ret, minUseB;
	Vert():ret(1e9){};
};
struct InfoCand{
	int cost, numUseB;
	Vert *vert, *from;
	InfoCand(int cost, int numUseB, Vert* vert, Vert* from):
		cost(cost), numUseB(numUseB), vert(vert), from(from){}
	bool operator < (const InfoCand& ic) const{
		return !(
				cost != ic.cost ? cost < ic.cost :
				numUseB < ic.numUseB);
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<Vert> vs(n);
	for(int i=0;i<m;i++){
		int c, a, b;
		cin >> c >> a >> b;
		if(a == b){ continue; }
		vs[a].edges.emplace_back(c, &vs[b]);
		vs[b].edges.emplace_back(c, &vs[a]);
	}
	priority_queue<InfoCand> cands;
	cands.emplace(0, 0, &vs[0], nullptr);

	int visited = 0;
	while(visited < n){
		auto minCand = cands.top();
		cands.pop();
		if(minCand.vert -> ret != 1e9){
			if(minCand.vert -> minUseB <= minCand.numUseB){ continue; }
		}else{
			minCand.vert -> ret = minCand.cost;
			visited++;
		}
		minCand.vert -> minUseB = minCand.numUseB;
		for(auto& e : minCand.vert -> edges){
			// if(minCand.from == e.dest){ continue; }
			if(e.type == 0){
				cands.emplace(minCand.cost + 1, minCand.numUseB, e.dest, minCand.vert);
			}else{
				cands.emplace(minCand.cost + 1 + minCand.numUseB, minCand.numUseB + 1, e.dest, minCand.vert);
			}
		}
	}

	for(auto& v : vs){
		cout << v.ret << endl;
	}
	return 0;
}