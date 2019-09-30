#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;

struct Hiker {
    long long t, lap;
    int id;
    Hiker() { }
    Hiker(long long t, long long lap, int id): t(t), lap(lap), id(id) { }
    bool operator < (const Hiker & oth) const {
        return t < oth.t || (t == oth.t && id < oth.id);
    }
};

int n;
int sum = 0;
set < Hiker > q;

void read() {
    q.clear();
    sum = 0;
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        int d, h; 
        long long m;
        scanf("%d%d%lld", &d, &h, &m);
        for (int j = 0; j < h; j++, m++) {
            long long st = (360 - d) * m;
            //q.insert(mp(st, m * 360));
            q.insert(Hiker(st, m * 360, sum + j)); 
        }
        sum += h;
    }
}

int solve() {
    int answer = sum;
    vector < bool > use(sum, 0);
    int cntD = sum;
    int cntAdd = 0;
    for (; cntAdd < answer; ) {
        long long t = q.begin()->t;
        for (; q.begin()->t == t; ) {
            auto tmp = *(q.begin());
            q.erase(q.begin()); 
            if (use[tmp.id] == 0) {
                cntD--;
                use[tmp.id] = 1;
            }
            else {
                cntAdd++;
            }
            q.insert(Hiker(tmp.t + tmp.lap, tmp.lap, tmp.id));
        }
        answer = min(answer, cntD + cntAdd);
    }

    return answer;
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            cerr << "test " << tt << endl;
            printf("Case #%d: ", tt + 1);
            read();
            printf("%d\n", solve());
        }
    }
    else {
        stress();
    }

    return 0;
}

