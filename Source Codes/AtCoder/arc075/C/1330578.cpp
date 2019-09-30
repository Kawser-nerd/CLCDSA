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
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
template <ostream& out = cout, class... T> void printBTree(T&&...){ }
#endif

struct AVLNode{
    ll value;
    ll cnt = 1;
    AVLNode *l = nullptr, *r = nullptr;
    int height;
    AVLNode(ll v): value(v), height(1){ }
    void updateHeight(){
        height = 1 + max(l ? l->height : 0, r ? r->height : 0);
    }
    AVLNode* add(ll v){
        if(v == value){ cnt++; return this; }
        auto& child = v < value ? l : r;
        if(&child == &r){
            cnt++;
        }
        if(child){
            child = child->add(v);
        }else{
            child = new AVLNode(v);
        }
        updateHeight();
        return check();
    }
    AVLNode* check(){
        int ld = l ? l->height : 0, rd = r ? r->height : 0;
        // prints(height, l, r, ld, rd);
        if(abs(ld - rd) <= 1){ return this; }
        // auto small = ld < rd ? l : r;
        auto& large = ld >= rd ? l : r;
        int lld = large->l ? large->l->height : 0, rrd = large->r ? large->r->height : 0;
        if((ld < rd && lld > rrd) || (ld > rd && lld < rrd)){
            large = large->rotate(lld >= rrd);
        }
        return rotate(ld >= rd);
    }
    AVLNode* rotate(bool leftChild){
        AVLNode *AVLNode::*left = leftChild ? &AVLNode::l : &AVLNode::r,
                *AVLNode::*right = leftChild ? &AVLNode::r : &AVLNode::l;
        auto child = this->*left;
        if(leftChild){
            child->cnt += cnt;
        }else{
            cnt -= child->cnt;
        }
    // (child->*right)->cnt += cnt;
        this->*left = child->*right;
        child->*right = this;
        child->updateHeight();
        updateHeight();
        return child;
    }
};
struct AVLTree{
    AVLNode* root = nullptr;
    ll added = 0;
    void add(ll v){
        added -= v;
        v += added;
        if(!root){
            root = new AVLNode(v);
        }else{
            root = root->add(v);
        }
    }
    ll beq(ll num){
        num += added;
        AVLNode* n = root;
        ll acc = 0;
        while(n){
            if(n->value > num){
                acc += n->cnt;
                n = n->l;
            }else if(n->value == num){
                return n->cnt + acc;
            }else{
                n = n->r;
            }
        }
        return acc;
    }
};
struct Node{
    Node *l = nullptr, *r = nullptr;
    ll value, cnt = 1;
    Node(ll value): value(value) { }
};
struct Sorted {
    Node* root = nullptr;
    ll added = 0;
    void insert(ll num){
        added -= num;
        num += added;
        Node* n = root;
        if(!root){ root = new Node(num); return; }
        while(n){
            // prints(n);
            if(n->value <= num){
                n->cnt++;
                if(!n->r){ n->r = new Node(num); break; }
                n = n->r;
            }else{
                // n->cnt++;
                if(!n->l){ n->l = new Node(num); break; }
                n = n->l;
            }
        }
        // n = new Node(num);
    }
    ll beq(ll num){
        num += added;
        Node* n = root;
        ll acc = 0;
        while(n){
            if(n->value > num){
                acc += n->cnt;
                n = n->l;
            }else if(n->value == num){
                return n->cnt + acc;
            }else{
                n = n->r;
            }
        }
        return acc;
    }
    // int add(int num){
    //     added += num;
    // }
};

int main(){
    int n, k;
    cin >> n >> k;
    // Sorted sorted;
    AVLTree sorted;
    vector<int> as(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    reverse(as.begin(), as.end());
    for(int i = 0; i < n; i++){
        int a = as[i];
        a -= k;
        // ans += sorted.beq(- a);
        // sorted.add(a);
        // sorted.insert(a);
        sorted.add(a);
        ans += sorted.beq(0);
        printd(ans);
        printd(sorted.added);
        printBTree(sorted.root);
    }
    cout << ans << '\n';
    return 0;
}