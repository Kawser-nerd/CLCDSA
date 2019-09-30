#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
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
typedef long long ll;

int field[55][55], H, W, block;
int dh[] = { -1, 0, 1, 0};
int dw[] = { 0, 1, 0, -1};


int bfs() {
    int res = -1, cnt = 0;
    
    queue<pair<int,int>> pre, nxt;
    pre.push({1,1});
    
    while( !pre.empty() ) {
        pair<int,int> p = pre.front(); pre.pop();
        
        if ( p.first==H && p.second==W ) {
            res = cnt;
            break;
        }
        
        for ( int i=0; i<4; i++) {
            if ( field[p.first+dh[i]][p.second+dw[i]] == 1 ) {
                nxt.push({ p.first+dh[i], p.second+dw[i]});
                field[p.first+dh[i]][p.second+dw[i]] = 0;
            }
        }
        
        if ( !pre.empty()) continue;
        else {
            cnt++;
            swap( pre, nxt);
        }
    }
    return res;
}

int main() {
    cin >> H >> W;
    mem( field, 0);
    
    char c; block = 0;
    rep1( i, H)rep1( j, W) {
        cin >> c;
        if ( c=='.') field[i][j] = 1;
        else block++;
    }
    
    int cost = bfs();
    
    if ( cost == -1 ) {
        cout1(cost);
    } else {
        cout1( H*W - block - cost - 1);
    }
}