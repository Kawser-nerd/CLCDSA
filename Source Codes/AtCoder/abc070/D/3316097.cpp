#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define loop3(i,j,k,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)
#define loop4(i,j,k,l,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)for(int l=0; l<a; l++)if(i!=l&&j!=l&&k!=l)
#define rep1(i,a) for(int i=1; i<=a; i++)

#define scnd1(a) scanf("%d", &a)
#define scnd2(a,b) scanf("%d%d", &a,&b)
#define scnd3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define scnd4(a,b,c,d) scanf("%d%d%d%d", &a,&b,&c,&d)

#define cin1(a) cin >> a;
#define cin2(a,b) cin >> a >> b;
#define cin3(a,b,c) cin >> a >> b >> c;
#define cin4(a,b,c,d) cin >> a >> b >> c >> d;
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define prtd1(a) printf("%d\n", a)
#define prtd2(a,b) printf("%d %d\n", a,b)
#define prtd3(a,b,c) printf("%d %d %d\n", a,b,c)
#define prtd4(a,b,c,d) printf("%d %d %d %d\n", a,b,c,d)

#define mem(a,n) memset( a, n, sizeof(a))
#define INF 1000000000
typedef long long ll;

vector<vector<pair<int,int>>> G(100009);
ll d[100009];

void bfs(int s) {
    
    mem(d,-1);
    d[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    while( !q.empty() ){
        
        int u = q.front(); q.pop();
        //cout1(u);
        for(int v=0; v<G[u].size(); v++){
            pair<int,int> t = G[u][v];
            if(d[t.first]!=-1) continue;
            d[t.first] = d[u] + t.second;
            q.push(t.first);
        }
    }
}

int main() {
    int N, Q, K;
    cin >> N;
    
    rep(i,N-1){
        int a, b, c; scnd3(a,b,c);
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    
    cin >> Q >> K;
    bfs(K);
    
    rep(i,Q){
        int x, y; scnd2(x,y);
        cout1(d[x]+d[y]);
    }
}