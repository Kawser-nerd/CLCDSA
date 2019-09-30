#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
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

int G[55];
vector<pair<int,int>> edge;

int u_root( int a, int u_array[]) {
    if (u_array[a] == a) return a;
    u_array[a] = u_root(u_array[a], u_array);
    return u_array[a];
}

void u_connect( int a, int b, int u_array[]){
    int pa = u_root(a, u_array);  // ????a??
    int pb = u_root(b, u_array);  // ????b??
    
    if (pa==pb) return;         // ?????????????
    else u_array[pb] = pa;      // ?????????a???????
}

bool u_same( int a, int b, int u_array[]) {
    return u_root(a, u_array)==u_root(b, u_array);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    rep(i,M){
        int u, v;
        cin >> u >> v;
        edge.push_back({u,v});
    }
    
    int cnt=0;
    rep(i,M){
        rep1(j,N) G[j] = j;
        rep(j,M){
            if(i==j) continue;
            u_connect(edge[j].first, edge[j].second, G);
        }
        rep1(i,N){
            if(!u_same(1,i,G)){
                cnt++;
                break;
            }
        }
    }
    cout1(cnt);
}