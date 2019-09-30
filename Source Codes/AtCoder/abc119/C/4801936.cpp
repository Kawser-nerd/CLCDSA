#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int A, B, C, N;
const int max_n = 8;
vector<int> l(max_n+1, 0);
int rtn = 2000000000;

void calc(vector<char> v) {
    int mp = 0;
    int cnta = 0, cntb = 0, cntc = 0;
    for(int i = 1; i <= N; i++) {
        if(v[i] == 'A') {
            if(cnta != 0) mp += 10;
            cnta += l[i];
        } else if(v[i] == 'B') {
            if(cntb != 0) mp += 10;
            cntb += l[i];
        } else if(v[i] == 'C') {
            if(cntc != 0) mp += 10;
            cntc += l[i];
        }
    }
    if(cnta == 0 || cntb == 0 || cntc == 0) return;
    mp += abs(A - cnta) + abs(B - cntb) + abs(C - cntc);
    rtn = min(rtn, mp);
}

void dfs(int depth, vector<char> v) {
    if(depth > N) {
        calc(v);
        return;
    }
    for(int i = 0; i < 4; i++) {
        v[depth] = 'A' + i;
        dfs(depth+1, v);
    }
}

int main() {
    cin >> N >> A >> B >> C;
    for (int i = 1; i <= N; i++) cin >> l[i];
    
    vector<char> v(N+1, '0');
    dfs(1, v);
    cout << rtn << endl;
}