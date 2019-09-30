#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

struct Node;
struct Edge{
	Node *from, *to;
	ll limit, rem;
    Edge(){ }
	Edge(Node* from, Node* to, ll limit = 1): from(from), to(to), limit(limit), rem(limit){ }
    ll remain(bool rev = false){
        return rev ? limit - rem : rem;
    }
    void pour(ll f, bool rev = false){
        rem -= rev ? - f : f;
    }
};
int numNodes = 0;
struct Node{
    int id;
	vector<Edge*> inEdges, outEdges;
    Node(): id(numNodes++){ }
    Edge* add(Edge* e){
        outEdges.push_back(e);
        e->to->inEdges.push_back(e);
        return e;
    }
};
ll flow(Node* start, Node* goal, vector<char>& visited, ll cur){
	if(start == goal){ return cur; }
    prints(start->id, start->outEdges);
    auto _flow = [&](Node* Edge::* to, vector<Edge*> Node::* edges, bool rev = false){
        for(Edge* e : start->*edges){
            Node* v = e->*to; 
            if(!e->remain(rev) || visited[v->id]){ continue; }
            visited[v->id] = true;
            ll lim = min(cur, e->remain(rev));
            if((lim = flow(v, goal, visited, lim))){
                e->pour(lim, rev);
                prints("pour", lim);
                return lim;
            }
        }
        return 0ll;
    };
    ll ret = 0;
    if((ret = _flow(&Edge::to, &Node::outEdges)) ||
       (ret = _flow(&Edge::from, &Node::inEdges, true))){
        return ret;
    }
	return ret;
}
ll maxFlow(Node* start, Node* goal){
	if(start == goal){ exit(1); }
	ll ret = 0;
    while(1){
        vector<char> visited(numNodes);
        ll f;
		if(!(f = flow(start, goal, visited, MLL))){
            break;
        }
        ret += f;
	}
	return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<Node> nodes(n + 1);
    Node sn, tn;
    vector<Edge> edges(10 * n);
    int eidx = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(a > 0){
            sum += a;
            edges[eidx] = Edge(&nodes[i], &tn, a);
            nodes[i].add(&edges[eidx]);
            eidx++;
        }else{
            edges[eidx] = Edge(&sn, &nodes[i], - a);
            sn.add(&edges[eidx]);
            eidx++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + i; j <= n; j += i){
            edges[eidx] = Edge(&nodes[i], &nodes[j], MLL);
            nodes[i].add(&edges[eidx]);
            eidx++;
        }
    }
    ll mi = maxFlow(&sn, &tn);
    cout << sum - mi << '\n';
}