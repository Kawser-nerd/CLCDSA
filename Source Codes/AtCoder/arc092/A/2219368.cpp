#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define CK(N, A, B) (A <= N && N < B)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = (b - 1); a <= i; i--)
#define F first
#define S second
#define ll long long

const int INF = 1e9;
const long long LLINF = 1e18;

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dy8[] = {0,1,1,1,0,-1,-1,-1};
int dx8[] = {1,1,0,-1,-1,-1,0,1};

/*==================================================*/
/*variable*/
int N;
int a[110], b[110], c[110], d[110];
pair<int,int> red[110], blue[110];

/*==================================================*/
/*function*/

/*==================================================*/

int main() {
    cin>>N;
    REP(i,0,N){
        //cin>>a[i]>>b[i];
        int x, y;
        cin>>x>>y;
        red[i] = make_pair(x, y);
    }
    REP(i,0,N){
        //cin>>c[i]>>d[i];
        int x, y;
        cin>>x>>y;
        blue[i] = make_pair(x, y);
    }

    sort(blue, blue+N);
    sort(red, red+N);

    set<int> usedr;

    REP(i,0,N){
        int miny = 210;
        int tj = -1;
        RREP(j,0,N){
            if(usedr.find(j) != usedr.end()) continue;
            if(blue[i].F < red[j].F || blue[i].S < red[j].S) continue;
            if(miny > blue[i].S - red[j].S){
                miny = blue[i].S - red[j].S;
                tj = j;
            }
        }
        if(tj != -1){
            usedr.insert(tj);
        }
    }

    cout<<usedr.size()<<endl;

    return 0;
}