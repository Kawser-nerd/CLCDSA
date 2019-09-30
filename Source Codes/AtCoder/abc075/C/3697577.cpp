#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct UnionFind
{
    vector<int> data;
    UnionFind() {}
 
    // initialize
    UnionFind(int size) : data(size, -1) {}
 
    void unite_set(int x, int y){
        x = root(x);
        y = root(y);
        bool is_unite = (x != y);
        
        if (is_unite){
            if (data[y] < data[x]){
                swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
    }
 
    bool is_same(int x, int y){
        return root(x) == root(y);
    }
 
    int root(int x){
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }
 
    int size(int x){
        return -data[root(x)];
    }
};

int main()
{
    int n, m;
    int ans, a, b;
    ans = 0;
    cin >> n >> m;
    vector<int> data;
    vector<pair<int, int>> edge(m);
    data.resize(n);
    
    for (int i=0; i<n; ++i){
        data[i] = i;
    }
    for (int i=0; i<m; ++i){
        cin >> a >> b;
        edge[i] = make_pair(a, b);
    }
    for (int i=0; i<m; ++i){
        struct UnionFind d(n);
        for (int j=0; j<m; ++j){
            if(j == i){continue;}
            d.unite_set(edge[j].first-1, edge[j].second-1);
        }
        for (int j=0; j<n; ++j){
            if(j == n-1){
                if(!d.is_same(data[n-1], data[0])){
                    ans++;
                    break;
                }
            }
            else {
                if(!d.is_same(data[j], data[j+1])){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}