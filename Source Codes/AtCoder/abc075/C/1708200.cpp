//
// C - Bridge
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> G[51];

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int count = 0;
    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 1; i <= N; i++) {
            if (G[i].size() == 1) {
                G[i].clear();
                count++;
                changed = true;
                for (int j = 1; j <= N; j++) {
                    G[j].erase(remove(G[j].begin(), G[j].end(), i), G[j].end());
                }
            }
        }
    }

    cout << count << endl;
}