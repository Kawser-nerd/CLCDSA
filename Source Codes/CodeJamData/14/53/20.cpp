#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int oo = 0x3f3f3f3f;

int E, N;
vector< pair<int, int> > Events;
vector< vector<int> > DP;

inline int GetBit(const int mask, const int bit) {
    return (mask >> bit) & 1;
}

inline int GetDP(const int when, const int mask) {
    if (when == -1)
        return 1;
    if (DP[when][mask] != -1)
        return DP[when][mask];
    DP[when][mask] = 0;
    int bit = Events[when].first, id = Events[when].second;
    if (id != -1) {
        if (GetBit(mask, id) == bit)
            return DP[when][mask] = GetDP(when - 1, mask ^ (1 << id));
        else
            return DP[when][mask] = 0;
    } else {
        for (id = 0; id < N; ++id)
            if (GetBit(mask, id) == bit)
                DP[when][mask] |= GetDP(when - 1, mask ^ (1 << id));
        return DP[when][mask];
    }
    return DP[when][mask] = 0;
}

void NormalizeIDs() {
    unordered_map<int, int> hash;
    for (int i = 0, j = 0; i < E; ++i) {
        if (Events[i].second == 0) {
            Events[i].second = -1;
        } else {
            if (hash.count(Events[i].second) == 0)
                hash[Events[i].second] = j++;
            Events[i].second = hash[Events[i].second];
        }
    }
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCases;
    cin >> testCases;
    for (int test = 1; test <= testCases; ++test) {
        cin >> E;
        N = E;
        Events = vector< pair<int, int> >(E, pair<int, int>());
        for (int i = 0; i < E; ++i) {
            char type;
            int bit, id;
            cin >> type >> id;
            if (type == 'E')
                bit = 1;
            else
                bit = 0;
            Events[i] = make_pair(bit, id);
        }
        NormalizeIDs();
        DP = vector< vector<int> >(E, vector<int>(1 << N, -1));
        int answer = oo;
        for (int mask = 0; mask < (1 << N); ++mask) {
            int count = 0;
            for (int id = 0; id < N; ++id)
                if (GetBit(mask, id) == 1)
                    ++count;
            if (GetDP(E - 1, mask) == 1)
                answer = min(answer, count);
        }
        cout << "Case #" << test << ": ";
        if (answer == oo)
            cout << "CRIME TIME\n";
        else
            cout << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
