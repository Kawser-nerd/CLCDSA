#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <sstream>

#define FOR(x,a,b) for(int x=(a); x<(b); x++)
#define FI(b) FOR(i,0,b)
#define FJ(b) FOR(j,0,b)
#define FK(b) FOR(k,0,b)
#define FC(b) FOR(c,0,b)
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin(); it!=v.end(); it++)

using namespace std;

int main() {
	int cases;
	cin >> cases;
	FC(cases) {
        int quesN, submitN;
        cin >> submitN >> quesN;

        vector< vector<long double> > P(quesN);
        FI(quesN) {
            P[i].resize(4);
            FJ(4) cin >> P[i][j];
            sort(P[i].begin(), P[i].end());
            reverse(P[i].begin(), P[i].end());
        }

        //FI(quesN) {
            //FJ(4) cout << P[i][j] << "  "; cout <<endl;
        //}

        priority_queue<pair<long double, vector<int> > > q;
        vector<int> cur(quesN);
        long double initP = 1;
        for(int i=0; i<quesN; i++) initP *= P[i][0];
        q.push(make_pair(initP, cur));

        long double ans = 0;
        set<vector<int> > vis;
        while(!q.empty() && submitN > 0) {
            //cout << q.top().first<<endl;
            vector<int> cur = q.top().second;
            double curP = q.top().first;
            q.pop();
            if (vis.count(cur)) continue;
            vis.insert(cur);

            submitN--;
            ans += curP;


            FI(cur.size()) {
                if (cur[i] == 3) continue;
                vector<int> next = cur;
                next[i]++;

                long double nextP = 1;
                FJ(next.size()) {
                    nextP *= P[j][ next[j] ];
                }

                q.push(make_pair(nextP, next));
            }
            
        }

        cout << "Case #" << (c+1) << ": " << ans<<endl;
	}
}
