#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;
const int NIL = -1;

vector< vector< pair<int, int> > > Tree;
int V, E;
vector<int> Values;
vector< vector< vector< vector<int> > > > DP;
vector<bool> UsedEdges;
vector<int> UsedVertices;

inline bool GameOver(const int fromA, const int toA, const int fromB, const int toB) {
    for (const auto &e: Tree[toA])
        if (!UsedEdges[e.second])
            return false;
    for (const auto &e: Tree[toB])
        if (!UsedEdges[e.second])
            return false;
    return true;
}

int GetDP(const int fromA, const int toA, const int fromB, const int toB) {
    if (DP[fromA][toA][fromB][toB] != -oo)
        return DP[fromA][toA][fromB][toB];
    if (GameOver(fromA, toA, fromB, toB))
        return 0;
    bool canMove = false;
    DP[fromA][toA][fromB][toB] = -oo + 1;
    for (const auto &e: Tree[toA]) {
        if (UsedEdges[e.second])
            continue;
        canMove = true;
        int win = Values[e.first];
        if (UsedVertices[e.first] > 0)
            win = 0;
        UsedEdges[e.second] = true;
        ++UsedVertices[e.first];
        DP[fromA][toA][fromB][toB] = max(DP[fromA][toA][fromB][toB], win - GetDP(fromB, toB, fromA, e.first));
        UsedEdges[e.second] = false;
        --UsedVertices[e.first];
    }
    if (!canMove)
        DP[fromA][toA][fromB][toB] = -GetDP(fromB, toB, fromA, toA);
    return DP[fromA][toA][fromB][toB];
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCases;
    cin >> testCases;
    for (int test = 1; test <= testCases; ++test) {
        cin >> V;
        E = V - 1;
        Tree = vector< vector< pair<int, int> > >(V, vector< pair<int, int> >());
        Values = vector<int>(V);
        for (int x = 0; x < V; ++x)
            cin >> Values[x];
        for (int e = 0, x = 0; e < E; ++e, ++x) {
            int y;
            cin >> y;
            --y;
            Tree[x].push_back(make_pair(y, e));
            Tree[y].push_back(make_pair(x, e));
        }
        DP = vector< vector< vector< vector<int> > > >(V, vector< vector< vector<int> > >(V, vector< vector<int> >(V, vector<int>(V, -oo))));
        int answer = -oo;
        for (int x = 0; x < V; ++x) {
            int winNow = oo;
            for (int y = 0; y < V && winNow > answer; ++y) {
                UsedEdges = vector<bool>(E, false);
                UsedVertices = vector<int>(V, 0);
                ++UsedVertices[x];
                ++UsedVertices[y];
                if (x != y)
                    winNow = min(winNow, Values[x] - Values[y] + GetDP(x, x, y, y));
                else
                    winNow = min(winNow, Values[x] + GetDP(x, x, y, y));
            }
            answer = max(answer, winNow);
        }
        cout << "Case #" << test << ": " << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
