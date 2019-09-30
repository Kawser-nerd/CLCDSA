#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
template <class... T> void printArr(T&&...){ }
#endif

chrono::steady_clock clk;
auto startTime = clk.now();

struct Node;
struct Edge{
	Node *from, *to;
	int limit, rem;
	Edge(Node* from, Node* to, int limit = 1): from(from), to(to), limit(limit), rem(limit){ }
    bool full(bool rev = false){
        return rev ? rem == limit : rem == 0;
    }
    void pour(int f, bool rev = false){
        rem -= rev ? - f : f;
    }
};
struct Node{
	vector<Edge*> inEdges, outEdges;
    Edge* add(Node* dest){
        Edge* e = new Edge(this, dest);
        outEdges.push_back(e);
        dest->inEdges.push_back(e);
        return e;
    }
    pair<Edge*, Edge*> add2(Node* dest){
        return {add(dest), dest->add(this)};
    }
};
int flow(Node* start, Node* goal, set<Node*>& visited, int cur){
	if(start == goal){ return cur; }
    auto _flow = [&](Node* Edge::* to, vector<Edge*> Node::* outEdges, bool rev = false){
        for(Edge* e : start->*outEdges){
            Node* v = e->*to; 
            if(e->full(rev) || visited.count(v)){ continue; }
            visited.insert(v);
            if(flow(v, goal, visited, cur)){
                e->pour(1, rev);
                return 1;
            }
        }
        return 0;
    };
    int ret = 0;
    if((ret = _flow(&Edge::to, &Node::outEdges)) ||
       (ret = _flow(&Edge::from, &Node::inEdges, true))){
        return ret;
    }
	return ret;
}
int maxFlow(Node* start, Node* goal, int lim){
	if(start == goal){ exit(1); }
	int cnt = 0;
	for(;;cnt++){
		set<Node*> visited;
		if(!flow(start, goal, visited, 1e9 + 7)){ break; }
        prints(cnt);
        if(clk.now() - startTime > 1800ms){
            return lim;
        }
	}
	return cnt;
}

int main(){
    int h, w;
    cin >> h >> w;
    vector<Node> nodes(h * w * 2);
    vector<string> as(h);
    Node *start, *goal;
    int sy, sx, ty, tx;
    for(int i = 0; i < h; i++){
        cin >> as[i];
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(as[i][j] == 'S'){
                sy = i; sx = j;
                start = &nodes[i * w + j + h * w];
            }else if(as[i][j] == 'T'){
                ty = i; tx = j;
                goal = &nodes[i * w + j];
            }
        }
    }
    if(sy == ty || sx == tx){
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(as[i][j] == '.'){ continue; }
            auto &n1 = nodes[i * w + j], &n2 = nodes[i * w + j + h * w];
            n1.add2(&n2);
            for(int k = 0; k < h; k++){
                if(as[k][j] == '.' || i == k){ continue; }
                auto &nt1 = nodes[k * w + j], &nt2 = nodes[k * w + j + h * w];
                n2.add(&nt1);
                nt2.add(&n1);
            }
            for(int k = 0; k < w; k++){
                if(as[i][k] == '.' || j == k){ continue; }
                auto &nt1 = nodes[i * w + k], &nt2 = nodes[i * w + k + h * w];
                n2.add(&nt1);
                nt2.add(&n1);
            }
        }
    }
    int lim1 = 0, lim2 = 0;
    for(int i = 0; i < h; i++){
        lim1 += as[i][sx] == 'o';
        lim2 += as[i][tx] == 'o';
    }
    for(int i = 0; i < w; i++){
        lim1 += as[sy][i] == 'o';
        lim2 += as[ty][i] == 'o';
    }
    cout << maxFlow(start, goal, min(lim1, lim2)) << '\n';
    return 0;
}