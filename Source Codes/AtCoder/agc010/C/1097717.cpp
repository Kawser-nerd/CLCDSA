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
#endif

struct Node{
    vector<Node*> dests;
    ll a;
    void add(Node* n){
        dests.push_back(n);
    }
    void add2(Node* n){
        add(n);
        n->add(this);
    }
    int dfs(Node* from = nullptr){
        vector<int> ret;
        int sum = 0, maxi = 0, cnt = 0;
        for(Node* d : dests){
            if(d == from){ continue; }
            ret.push_back(d -> dfs(this));
            sum += ret.back();
            maxi = max(maxi, ret.back());
            cnt++;
        }
        if(!cnt){ return a; }
        if(sum < a || a - (sum - a) < 0){
            cout << "NO" << '\n';
            exit(0);
        }
        int lim = M;
        if(sum - maxi < maxi){
            lim = sum - maxi;
        }
        if(lim < sum - a){
            cout << "NO" << '\n';
            exit(0);
        }
        prints(a - (sum - a));
        return a - (sum - a);
    }
    // pair<ll, ll> dfs(Node* from = nullptr){
    //     vector<pair<ll, ll>> vp;
    //     int cnt = 0;
    //     bool even = true;
    //     for(Node* d : dests){
    //         if(d == from){ continue; }
    //         cnt++;
    //         vp.push_back(d -> dfs(this));
    //     }
    //     if(!cnt){ return {a, a}; }
    //     ll mini = 0, maxi = 0, mami = 0, mama = 0;
    //     for(auto p : vp){
    //         even ^= p.first % 2;
    //         mini += p.first;
    //         maxi += p.second;
    //         mami = max(mami, p.first);
    //         mama = max(mama, p.second);
    //     }
    //     if(a < mami || a < (mini + 1) / 2){
    //         cout << "NO" << '\n';
    //         exit(0);
    //     }
    //     ll rmi = a, rma = a;
    //     rmi = maxi - mama + 2 <= mama ? a - (maxi - mama) : a - maxi / 2;
    //     if(rmi < 0){
    //         rmi = 0;
    //     }
    //     // rma = mini <= a ? a : a - (mini + 1) / 2;
    //     rma = mini <= a ? a : a - (mini - a);
    //     prints(a, rmi, rma);
    //     return {rmi, rma};
    // }
};

int main(){
    int n; cin >> n;
    vector<Node> nodes(n);
    for(int i=0;i<n;i++){
        cin >> nodes[i].a;
    }
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        nodes[a].add2(&nodes[b]);
    }
    Node* leaf;
    for(Node& n : nodes){
        if(n.dests.size() == 1){
            leaf = &n;
            break;
        }
    }
    prints("leaf", leaf - &nodes[0]);
    auto p = leaf->dests[0]->dfs(leaf);
    // cout << (p.first <= leaf->a && leaf->a <= p.second ? "YES" : "NO") << '\n';
    cout << (p == leaf->a ? "YES" : "NO") << '\n';
    return 0;
}