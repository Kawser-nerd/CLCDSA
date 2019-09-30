#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>

#define MOD (1000000007)
#define MAX (2010)

using namespace std;

typedef long long int Int;

Int N,M;
Int X;
struct Graph {
    Int u,v,w;
    bool operator < (const struct Graph &right) const {
        return w < right.w;
    }
}G[MAX];

int pa[MAX];
int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}

Int modPow(int x) {
    Int res = 1;
    for(int i = 0;i < x;i++) {
        res = res * 2 % MOD;
    }

    return res;
}

int main(void) {
    cin>>N>>M;
    cin>>X;
    
    for(int i = 0;i < M;i++) {
        Int u,v,w;
        cin>>u>>v>>w;
        G[i].u = --u;
        G[i].v = --v;
        G[i].w = w;
    }

    sort(G,G+M);

    Int cnt1 = 0,cnt2 = 0;
    for(int i = 0;i < M;i++) {
        for(int k = 0;k < N;k++)
            pa[k] = k;
        pa[find(G[i].u)] = find(G[i].v);
        Int cost = G[i].w;
        for(int j = 0;j < M;j++) {
            if(find(G[j].u) == find(G[j].v))
                continue;
            pa[find(G[j].u)] = find(G[j].v);
            cost += G[j].w;
        }
        if(cost < X)
            cnt1++;
        if(cost <= X)
            cnt2++;
    }

    cout<<(modPow(min(M,M-cnt1+1)) - modPow(min(M,M-cnt2+1)) + MOD ) % MOD<<endl;

    return 0;
}