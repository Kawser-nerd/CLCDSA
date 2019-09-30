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

int none = 0, black = 1, white = 2;
struct Node{
    vector<Node*> dests;
    int color = none;
    bool valid = true;
    void add(Node* n){
        dests.push_back(n);
    }
    void add2(Node* n){
        add(n);
        n->add(this);
    }
    void dfs(Node* from = nullptr){
        for(Node* d : dests){
            if(d == from){ continue; }
            d -> dfs(this);
        }
    }
    void setColor(int c){
        if(!color){
            color = c;
        }
    }
    int validDests(){
        int ret = 0;
        for(Node* d : dests){
            ret += (d->valid);
        }
        return ret;
    }
    Node* getOne(){
        for(Node* d : dests){
            if(d->valid){
                return d;
            }
        }
        exit(1);
    }
};

int main(){
    int n; cin >> n;
    vector<Node> nodes(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        nodes[a].add2(&nodes[b]);
    }
    while(1){
        vector<pair<Node*, Node*>> cps;
        for(int i=0;i<n;i++){
            if(nodes[i].valid && nodes[i].validDests() == 0){
                cout << "First" << '\n';
                return 0;
            }
            if(nodes[i].valid && nodes[i].validDests() == 1){
                cps.emplace_back(&nodes[i], nodes[i].getOne());
            }
        }
        if(cps.empty()){ break; }
        for(auto& cp : cps){
            if(cp.second->color && !cp.first->color){
                cout << "First" << '\n';
                return 0;
            }
            cp.first->color = white;
            cp.second->color = black;
            cp.first->valid = false;
            cp.second->valid = false;
        }
    }
    cout << "Second" << '\n';
    return 0;
}