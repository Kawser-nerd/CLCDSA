#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int Hd, Ad, Hk, Ak, B, D;
        cin >> Hd >> Ad >> Hk >> Ak >> B >> D;
        map< vector<int>, int > best;
        vector<int> start = { Hd, Ad, Hk, Ak };
        best[start] = 0;
        queue<vector<int> > Q;
        Q.push(start);
        int FOUND = -1;
        int STEPS = 0;
        while (!Q.empty()) {
            ++STEPS;
            if (STEPS > 98765432) { cerr << "ZLE JE\n"; break; }
            vector<int> curr = Q.front(); Q.pop();
            int chd = curr[0], cad = curr[1], chk = curr[2], cak = curr[3];
            // dead?
            if (chd == 0) continue;
            if (chk == 0) { FOUND = best[curr]; break; }
            {
                // attack
                int nhk = max( 0, chk - cad );
                int nhd = chd;
                if (nhk > 0) nhd = max( 0, chd - cak );
                vector<int> foll = { nhd, cad, nhk, cak };
                if (!best.count(foll)) { best[foll] = best[curr]+1; Q.push(foll); }
            }
            if (B > 0) {
                // buff
                int nad = cad + B;
                int nhd = max( 0, chd - cak );
                vector<int> foll = { nhd, nad, chk, cak };
                if (!best.count(foll)) { best[foll] = best[curr]+1; Q.push(foll); }
            }
            {
                // cure
                int nhd = max( 0, Hd - cak );
                vector<int> foll = { nhd, cad, chk, cak };
                if (!best.count(foll)) { best[foll] = best[curr]+1; Q.push(foll); }
            }
            if (D > 0 && cak > 0) {
                // debuff
                int nak = max( 0, cak - D );
                int nhd = max( 0, chd - nak );
                vector<int> foll = { nhd, cad, chk, nak };
                if (!best.count(foll)) { best[foll] = best[curr]+1; Q.push(foll); }
            }
        }
        if (FOUND == -1) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << FOUND << endl;
        }
    }
}
