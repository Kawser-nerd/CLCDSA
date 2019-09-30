#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

#define REP(i, n) for ( int i = 0; i < (n); i++ ) 
#define FOR(i, a, b) for ( int i = (a); i < (b); i++ ) 

using namespace std;

const int MAX_W = 22;
set<int> used[MAX_W][MAX_W];
char d[MAX_W][MAX_W];
int w, ce;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

struct el {
    int val;
    short x, y;
    list<char> path;

    el() {}
    el(int aval, short ax, short ay, const list<char>& apath) : val(aval), x(ax), y(ay), path(apath) {}

    bool operator<(const el& e) const {
        if ( path.size() != e.path.size() ) return path.size() < e.path.size();
        else if ( path != e.path ) return path < e.path;
        if ( val != e.val ) return val < e.val;
        if ( x < e.x ) return x < e.x;
        return y < e.y;
    }
};

void fun(int cs) {
    printf("Case #%d:\n", cs);
    scanf("%d %d", &w, &ce);
    REP(i, w) REP(j, w) {
        scanf(" %c", &d[i][j]);
        used[i][j].clear();
    }

    set<el> Q;
    REP(i, w) REP(j, w) {
        if ( d[i][j] == '-' or d[i][j] == '+' ) continue;
        list<char> li;
        li.push_back(d[i][j]);
        int val = d[i][j] - '0';    
        Q.insert(el(val, i, j, li));
        used[i][j].insert(val);
    }

    vector<int> data;
    set<int> cele;
    REP(i, ce) {
        int x;
        scanf("%d", &x);
        cele.insert(x);
        data.push_back(x);
    }
    map< int, list<char> > res;

    while ( Q.size() > 0 and cele.size() > 0 ) {
        list<char> path = (*Q.begin()).path;
        int x = (*Q.begin()).x;
        int y = (*Q.begin()).y;
        int val = (*Q.begin()).val;
//        printf("%d %d %d\n", val, x, y);

        Q.erase(Q.begin());

        if ( cele.find(val) != cele.end() ) {
            cele.erase(val);
            res[val] = path;
        }

        REP(dir, 4) {
            int nx = x + dirX[dir];
            int ny = y + dirY[dir];

            if ( nx < 0 or ny < 0 or nx >= w or ny >= w ) continue;

            int nval = val;
            if ( d[nx][ny] != '-' and d[nx][ny] != '+' ) {
                if ( path.back() == '-' )
                    nval = val - (d[nx][ny]-'0');
                else
                    nval = val + (d[nx][ny]-'0');
            }

            if ( used[nx][ny].find(nval) != used[nx][ny].end() ) continue;

            used[nx][ny].insert(nval);
            list<char> npath = path;
            npath.push_back(d[nx][ny]);
            Q.insert( el(nval, nx, ny, npath) );
//            printf("!\n");
        }
    }

    REP(i, data.size()) {
        int val = data[i];
        for ( list<char>::iterator it = res[val].begin(); it != res[val].end(); it++ ) {
            printf("%c", *it);
        }
        printf("\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    REP(i, T) fun(i+1);

    return 0;
}
