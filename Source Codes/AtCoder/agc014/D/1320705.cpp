#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cassert>

using namespace std;

int main() {
    int n; cin >> n;

    vector<set<int>> G(n);
    for (int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        G[a - 1].insert(b - 1);
        G[b - 1].insert(a - 1);
    }
   
    vector<int> vis(n);
    
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        if (G[i].size() <= 1) {
            q.push_back(i);
            vis[i] = true;
        }
    }

    auto remove_edge = [&G](int a, int b) {
        G[a].erase(b);
        G[b].erase(a);
    };

    while (!q.empty()) {
        int node = q.front();
        q.pop_front();
       
        if (vis[node] == 2) continue;
        if (G[node].empty()) {
            cout << "First" << endl;
            return 0;
        }


        int parent = *G[node].begin();
        vis[parent] = 2;

        remove_edge(node, parent);
        
        while (G[parent].size()) {
            int vec = *G[parent].begin();
            remove_edge(parent, vec);
            
            if (G[vec].size() <= 1 && vis[vec] == 0) {
                q.push_back(vec);
            }
        }
    }

    cout << "Second" << endl;
    return 0;
}