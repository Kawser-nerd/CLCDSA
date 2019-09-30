#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

string s[120];
//int to[N*M][2];
//vector<int> vg[10200];

// Union Find
int ufdata[200000];
void uf_init() { MEMSET(ufdata,-1); }
int uf_root(int x) { return ufdata[x]<0?x:ufdata[x]=uf_root(ufdata[x]); }
bool uf_find(int x,int y) { return uf_root(x) == uf_root(y); }
void uf_union(int x,int y) {
    x=uf_root(x); y=uf_root(y);
    if (x!=y) {
        if (ufdata[x]<ufdata[y]) swap(x,y);
        ufdata[x] += ufdata[y]; ufdata[y] = x;
    }
}

int mat[10200];
void solve_large() {
    int N,M; cin>>N>>M;
    REP(y, N) cin>>s[y];
    //REP(y,N) cout<<"#"<<s[y]<<endl;
    //REP(i, 10200) vg[i].clear();
    uf_init();

    MEMSET(mat, 0);
    REP(y, N) REP(x, M) {
        int ay0=y, ax0=x, ay1=y, ax1=x;
        if (s[y][x]=='-') ax0++, ax1--;
        if (s[y][x]=='|') ay0++, ay1--;
        if (s[y][x]=='\\') ax0++, ay0++, ax1--, ay1--;
        if (s[y][x]=='/')  ax0++, ay0--, ax1--, ay1++;
            // ugly
        ay0=(ay0+N)%N;
        ax0=(ax0+M)%M;
        ay1=(ay1+N)%N;
        ax1=(ax1+M)%M;
        int id0=ay0*M+ax0, id1=ay1*M+ax1;
        uf_union(id0, id1);
        mat[id0]++;
        //vg[id0].push_back(id1);
        //vg[id1].push_back(id0);
        //to[y*M+x][0] = ay0*M+ax0;
        //to[y*M+x][1] = ay1*M+ax1;
    }
        // yes graph theory
    map<int,int> cc;
    map<int,int> msum;
    REP(i, N*M) {
        cc[uf_root(i)]++;
        msum[uf_root(i)]+=mat[i];
    }

    FORIT(it, cc) {
        //cout<<"#"<<(it->first)<<endl;
        if (it->second == 1 || msum[it->first]!=it->second) { // edge
            puts("0");
            return;
        }
    }
    int cycle=SZ(cc);
    /*
    int cycle=0;
    MEMSET(visited, -1);
    REP(i, N*M) if (!visited[i]) {
        int f=dfs(i, cycle);
        if (f==1) cycle++;
        if (f==-1) { // edge case
            puts("0");
            return;
        }
    }
    */

    int res=1;
    REP(itr, cycle) res=(res*2)%1000003;
    printf("%d\n", res);
}

/*
void solve_small() {
    int N,M; cin>>N>>M;
    REP(y, N) cin>>s[y];
    int to[N*M][2];
    REP(y, N) REP(x, M) {
        int ay0=y, ax0=x, ay1=y, ax1=x;
        if (s[y][x]=='-') ax0++, ax1--;
        if (s[y][x]=='|') ay0++, ay1--;
        if (s[y][x]=='\\') ax0++, ay0++, ax1--, ay1--;
        if (s[y][x]=='/')  ax0++, ay0--, ax1--, ay1++;
            // ugly
        ay0=(ay0+N)%N;
        ax0=(ax0+N)%M;
        ay1=(ay1+N)%N;
        ax1=(ax1+N)%M;
        to[y*M+x][0] = ay0*M+ax0;
        to[y*M+x][1] = ay1*M+ax1;
    }
        // brute force
    int res=0;
    REP(bit, 1<<(N*M)) {
        set<int> st;
        REP(i, N*M) {
            int val = to[i][(bit>>i)&1];
            if (FIND(st, val)) goto SKIP;
            st.insert(val);
        }
        res++;
SKIP:;
    }
    printf("%d\n", res);
}
*/

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        //solve_small();
        solve_large();
    }
}
