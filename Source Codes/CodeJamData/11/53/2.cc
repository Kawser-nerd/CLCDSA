// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int R, C;
vector<string> img;

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        cin >> R >> C;
        img.clear();
        REP(r,R) { string tmp; cin >> tmp; img.push_back(tmp); }
        vector< vector<int> > outgoing(R*C);
        vector< vector<int> > incoming(R*C);
        REP(r,R) REP(c,C) {
            int dr=0, dc=0;
            REP(choice,2) {
                if (img[r][c]=='-') { if (choice & 1) dr=0, dc=-1; else dr=0, dc=1; }
                if (img[r][c]=='|') { if (choice & 1) dr=-1, dc=0; else dr=1, dc=0; }
                if (img[r][c]=='/') { if (choice & 1) dr=1, dc=-1; else dr=-1, dc=1; }
                if (img[r][c]=='\\') { if (choice & 1) dr=1, dc=1; else dr=-1, dc=-1; }
                int nr=(R+r+dr)%R, nc=(C+c+dc)%C;
                outgoing[C*r+c].push_back(C*nr+nc);
                incoming[C*nr+nc].push_back(C*r+c);
            }
        }
        int N = R*C;
        vector<bool> processed_left(N,false), processed_right(N,false), in_queue_right(N,false);
        queue<int> to_process;
        REP(n,N) if (SIZE(incoming[n])<2) {
            to_process.push(n);
            in_queue_right[n] = true;
        }
        bool FAIL = false;
        while (!to_process.empty()) {
            int kde = to_process.front(); to_process.pop();
            if (processed_right[kde]) continue;
            processed_right[kde] = true;
            in_queue_right[kde] = false;
            if (SIZE(incoming[kde])==0) { FAIL=true; break; }
            int parent = incoming[kde][0];
            // cout << "necessary " << kde << " " << parent << endl;
            processed_left[parent] = true;
            REP(i,2) if (outgoing[parent][i]!=kde) {
                int kam=outgoing[parent][i];
                REP(j,SIZE(incoming[kam])) if (incoming[kam][j]==parent) {
                    incoming[kam].erase( incoming[kam].begin()+j );
                    break;
                }
                if (SIZE(incoming[kam])<2) if (!in_queue_right[kam]) if (!processed_right[kam]) {
                    to_process.push(kam);
                    in_queue_right[kam] = true;
                }
            }
        }
        if (FAIL) {
            printf("Case #%d: 0\n",t);
            continue;
        }
        int komponenty = 0;
        REP(n,N) if (!processed_left[n]) {
            // cout << "new comp at " << n << endl;
            ++komponenty;
            processed_left[n]=true;
            int kde=n, prev=-1;
            while (true) {
                int right=-1;
                REP(i,2) if (outgoing[kde][i]!=prev) { right=outgoing[kde][i]; break; }
                int next=-1;
                REP(i,2) if (incoming[right][i]!=kde) next=incoming[right][i];
                if (next==n) break;
                processed_left[next]=true;
                prev=right;
                kde=next;
            }
        }
        int answer = 1;
        while (komponenty--) answer = (2*answer) % 1000003;
        printf("Case #%d: %d\n",t,answer);
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
