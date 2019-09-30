#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
typedef long long ll;
using namespace std;

int N;
int M;
int ans = 0;
vector<vector<int> > map(100);

void rcount(int current, vector<bool> been) {
    been[current] = true;
    if (all_of(been.begin(), been.end(), [](bool x){ return x; })) ans++;
    for (int i = 0; i < map[current].size(); i++) {
        if (!been[map[current][i]]) rcount(map[current][i], been);
    }
}

int main() {
    
    cin >> N;
    cin >> M;
    
    for (int i = 0; i<M; i++) {
        int _a; cin >> _a;
        int _b; cin >> _b;
        map[_a].push_back(_b);
        map[_b].push_back(_a);
    }
    
    vector<bool> been(N+1);
    for (int i = 0; i<been.size(); i++) {
        been[i] = false;
    }
    been[0] = true;
    int current = 1;
    rcount(current, been);
    cout << ans << endl;
    return 0;
}