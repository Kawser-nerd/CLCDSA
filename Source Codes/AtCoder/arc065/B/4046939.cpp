#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
//size??
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

int main(){
    int n;
    cin >> n;
    UnionFind uf(n+1),uf2(n+1);
    int k,l;
    cin >> k >> l;
    rep(tt,k){
        int a,b;
        cin >> a >> b;
        uf.unite(a,b);
    }
    rep(tt,l){
        int a,b;
        cin >> a >> b;
        uf2.unite(a,b);
    }
    map<ll,int> mp;
    rep(i,n){
        mp[(ll)uf.find(i+1)*((ll)uf2.find(i+1)+inf)]++;
    }
    rep(i,n){
        cout << mp[(ll)uf.find(i+1)*((ll)uf2.find(i+1)+inf)] << " ";
    }
    cout << endl;
    return 0;
}