#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <stack>

#define for_each(name, left, right) for (int name = left; name < (right); name++)
// #define show(x) cerr << #x << " = " << x << endl;


using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

void solve() {
    int pepl_nr, edges_nr;
    cin >> pepl_nr >> edges_nr;
    vector<vector<pii> > p_idx___neigh_idxes__dists(pepl_nr);
    for_each(edge_idx, 0, edges_nr) {
        int l_idx, r_idx, dist;
        cin >> l_idx >> r_idx >> dist;
        l_idx--; r_idx--;
        p_idx___neigh_idxes__dists[l_idx].push_back(make_pair(r_idx, dist));
        p_idx___neigh_idxes__dists[r_idx].push_back(make_pair(l_idx, -dist));
    }
    vi p_idx___color(pepl_nr, -1);
    int curr_color = 0;
    vi color___left_most;
    for_each(p_idx, 0, pepl_nr) {
        if (p_idx___color[p_idx] != -1) {
            continue;
        }
        stack<pii> stack_dfs;
        stack_dfs.push(make_pair(p_idx, 0));
        p_idx___color[p_idx] = curr_color;
        color___left_most.push_back(p_idx);
        int curr_min_dist = 0;
        while (!stack_dfs.empty()) {
            int curr_idx = stack_dfs.top().first;
            int curr_dist = stack_dfs.top().second;
            stack_dfs.pop();
            if (curr_dist < curr_min_dist) {
                color___left_most[curr_color] = curr_idx;
                curr_min_dist = curr_dist;
            }
            for (pii neigh__dist: p_idx___neigh_idxes__dists[curr_idx]) {
                int neigh_idx = neigh__dist.first;
                int dist = neigh__dist.second;
                int neigh_dist = curr_dist + dist;

                if (p_idx___color[neigh_idx] == -1) {
                    p_idx___color[neigh_idx] = curr_color;
                    stack_dfs.push(make_pair(neigh_idx, neigh_dist));
                }
                if (p_idx___color[neigh_idx] != curr_color) {
                    cerr << "error\n";
                    return;
                }
            }
        }
        // cout << color___left_most[curr_color] << endl;
        curr_color += 1;
    }
    vector<int> p_idx___visited(pepl_nr);
    vector<int> p_idx___dist(pepl_nr, -1);
    for(int left_most : color___left_most) {
        stack<int> stack_dfs;
        stack_dfs.push(left_most);
        p_idx___visited[left_most] = 1;
        p_idx___dist[left_most] = 0;
        while(!stack_dfs.empty()) {
            int curr_idx = stack_dfs.top();
            stack_dfs.pop();
            // cout << "*" << curr_idx << endl;
            for (pii neigh__dist : p_idx___neigh_idxes__dists[curr_idx]) {
                int neigh_idx = neigh__dist.first;
                int dist = neigh__dist.second;
                if (dist > 0 && p_idx___visited[neigh_idx] == 0) {
                    p_idx___visited[neigh_idx] = 1;
                    stack_dfs.push(neigh_idx);
                    if (p_idx___dist[neigh_idx] == -1) {
                        p_idx___dist[neigh_idx] = p_idx___dist[curr_idx] + dist;
                    }
                }
            }
        }
    }
    for_each(p1_idx, 0, pepl_nr) {
        for (pii p2__dist : p_idx___neigh_idxes__dists[p1_idx]) {
            int p2_idx = p2__dist.first;
            int dist = p2__dist.second;
            if (p_idx___dist[p2_idx] != p_idx___dist[p1_idx] + dist) {
                // cout << p1_idx << " " << p2_idx << " " << dist << endl;
                // cout <<  p_idx___dist[p1_idx] << " " << p_idx___dist[p2_idx] << endl;
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" <<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    // cout << 3 << endl << "6 3 1" << endl;
    solve();
}