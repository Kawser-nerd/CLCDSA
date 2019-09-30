#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#define INF 10000000000000000LL

using namespace std;

typedef pair<int,int> pii;

long long best(pii interv, vector<int>& v, map<pii, long long>& M) {
    map<pii, long long>::iterator it = M.find(interv);
    if (it != M.end()) return it->second;
    long long res = INF;
    for (int i = 0; i < v.size(); i++) {
        if (interv.first <= v[i] && v[i] <= interv.second) {
           long long now = best(pii(interv.first, v[i] - 1), v, M) + best(pii(v[i] + 1, interv.second), v, M);
           if (res > now) res = now;
        } 
    }
    if (res == INF) res = 0;
    else            res += interv.second - interv.first;
    
    return M[interv] = res;
}

long long calc() {
    int P, Q;
    cin >> P >> Q;
    vector<int> v(Q);
    for (int i = 0; i < Q; i++) cin >> v[i];
    map<pii, long long> M;
    return best(pii(1, P), v, M);
}

int main() {
    int T;
    cin >> T >> ws;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << calc() << endl;
    }
}
