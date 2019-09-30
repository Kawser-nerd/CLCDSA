//
// C - ?????
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int A, B;
vector<int> G[11];

int main() {

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {

        int count = 0;
        bool visited[11] = {false};
        queue<pair<int, int>> que;

        que.push(make_pair(i, 0));
        visited[i] = true;

        while (!que.empty()) {
            pair<int, int> &p = que.front();
            que.pop();
            if (p.second == 2) {
                count++;
                continue;
            }
            for (int j:G[p.first]) {
                if (!visited[j]) {
                    que.push(make_pair(j, p.second + 1));
                    visited[j] = true;
                }
            }
        }
        cout << count << endl;
    }
}