#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

int N;
ll L;

struct Node {
    int c[2] = {-1, -1};
};
vector<Node> v;

void dump (int node, int depth = 0) {

}

ll grundy(ll depth) {
    if (depth == 0) return 0;
    ll g = 1;
    while (depth != 0 && ((depth & 1) == 0)) {
        g <<= 1;
        depth >>= 1;
    }
    return g;
}

ll dfs(int node, int depth = 0) {
    Node n = v[node];
    ll g = 0;
    if (n.c[0] * n.c[1] < 0) {
        g = grundy(L - depth);
    }

    if (n.c[0] != -1) {
        g ^= dfs(n.c[0], depth + 1);
    }
    if (n.c[1] != -1) {
        g ^= dfs(n.c[1], depth + 1);
    }

    return g;
}

int main () {
    cin >> N >> L;

    Node root = Node();
    v.push_back(root);

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        int nodei = 0;
        for (int j = 0; j < s.size(); ++j) {
            int n = s[j] - '0';
            Node node = v[nodei];
            if (node.c[n] != -1) {
                nodei = node.c[n];
            } else {
                Node newnode = Node();
                v.push_back(newnode);
                v[nodei].c[n] = v.size() - 1;
                nodei = v.size() - 1;
            }
        }
    }

    ll g = 0;

    cout << (dfs(0) != 0 ? "Alice" : "Bob") << endl;
}