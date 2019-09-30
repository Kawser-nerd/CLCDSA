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
	Edge(Node* from, Node* to, int rem = 1): from(from), to(to), rem(rem){ }
	Node *from, *to;
	int rem;
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
bool flow(Node* start, Node* goal, set<Node*>& visited){
	if(start == goal){
		return true;
	}
	for(Edge* e : start -> outEdges){
		if(e -> rem == 0){ continue; }
		Node* v = e -> to; 
		if(visited.count(v)){ continue; }
		visited.insert(v);
		if(flow(v, goal, visited)){
			e -> rem --;
			return true;
		}
	}
	for(Edge* e : start -> inEdges){
		if(e -> rem != 0){ continue; }
		Node* v = e -> from; 
		if(visited.count(v)){ continue; }
		visited.insert(v);
		if(flow(v, goal, visited)){
			e -> rem ++;
			return true;
		}
	}
	return false;
}
int maxFlow(Node* start, Node* goal, int lim){
	int cnt = 0;
	for(;;cnt++){
		set<Node*> visited;
		if(!flow(start, goal, visited)){ break; }
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