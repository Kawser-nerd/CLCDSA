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

int G[10][10], d[10], cost[10];
bool visited[10];


void bfs(int x) {
    if(x==1) return;
    
    rep(i,10) d[i]=INF;
    mem( visited, false);
    int u = x;
    d[x] = 0;
    
    while(true){
        
        int minv = INF;
        visited[u] = true;

        for(int i=0; i<10; i++){
            if( d[i]>d[u]+G[u][i] ){
                d[i] = d[u]+G[u][i];
            }
        }
        
        for(int i=0; i<10; i++){
            if( !visited[i] && d[i]<minv ) {
                u = i;
                minv = d[i];
            }
        }
        
        if(u==1) {
            cost[x] = d[u];
            return;
        }
    }
    
}

int main() {
    int H, W;
    
    cin >> H >> W;
    
    rep(i,10)rep(j,10) cin >> G[i][j];
    
    rep(i,10) d[i] = INF;
    
    rep(i,10) bfs(i);
    
    int x, ans=0;
    rep(i,H) {
        rep(j,W){
            cin >> x;
            if(x==-1 || x==1) continue;
            ans += cost[x];
        }
    }
    
    cout1(ans);
}