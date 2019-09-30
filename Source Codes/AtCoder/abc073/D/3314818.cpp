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

int G[209][209];
vector<int> town;

void warshallFloyd(int n){
    
    int range=n;
    
    for(int k=1; k<=range; k++ ){
        for(int i=1; i<=range; i++ ){
            if(G[i][k]==INF) continue;
            for(int j=1; j<=range; j++ ){
                if(G[k][j]==INF) continue;
                if(G[i][j] > G[i][k]+G[k][j] ) G[i][j] = G[i][k]+G[k][j];
            }
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    
    rep1(i,N)rep1(j,N) G[i][j] = INF;
    
    rep(i,R){
        int t;
        cin >> t;
        town.push_back(t);
    }
    
    rep(i,M){
        int a, b, c;
        cin >> a >> b >> c;
        G[a][b] = c;
        G[b][a] = c;
    }
    
    warshallFloyd(N);
    
    ll ans=INF;
    sort(town.begin(),town.end());
    do{
        ll sum=0;
        //for(auto x : town) cout << x << " "; cout << "\n";
        for(int i=1; i<town.size(); i++){
            //cout2(town[i-1],town[i]);
            sum += G[ town[i-1] ][ town[i] ];
        }
        ans = min(ans,sum);
    }while( next_permutation(town.begin(), town.end()) );
    
    cout<<ans<<endl;
    
}