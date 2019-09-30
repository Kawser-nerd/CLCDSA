#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> a(n),b(m);
    rep(i,n)cin >> a[i];
    rep(i,m)cin >> b[i];
    bool flag = 0;
    for(int i=x+1;i<=y;i++){
        bool fflag = 1;
        rep(j,n){
            if(a[j]>=i)fflag = 0;
        }
        rep(j,m){
            if(b[j]<i)fflag = 0;
        }
        if(fflag)flag = 1;
    }
    if(flag){
        cout << "No War" << endl;
    }else{
        cout << "War" << endl;
    }
    return 0;
}