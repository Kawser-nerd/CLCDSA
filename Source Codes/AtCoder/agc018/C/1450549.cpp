#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 100005;
 
int X,Y,Z;
int n;
struct P {
    ll x,y,z;
    bool operator<(const P&a)const {
        return x+a.y>y+a.x;
    }
} p[maxn];
 
struct cmp1 {
    bool operator()(int x,int y) {
        return p[x].x+p[y].z>p[y].x+p[x].z;
    }
};
struct cmp2 {
    bool operator()(int x,int y) {
        return p[x].y+p[y].z<p[x].z+p[y].y;
    }
};
 
bool in_silver[maxn];
int main() {
   // freopen("in.cpp","r",stdin);
    cin>>X>>Y>>Z;
    n=X+Y+Z;
    for(int i=0; i<n; i++)cin>>p[i].x>>p[i].y>>p[i].z;
    sort(p,p+n);
    ll ret=0;
    priority_queue<int,vector<int>,cmp1>left_gold;
    priority_queue<int,vector<int>,cmp2>right_bronze;
    for(int i=0; i<X; i++) {
        ret+=p[i].x;
        left_gold.push(i);
    }
    for(int i=n-1; i>=X; i--) {
        ret+=p[i].z;
        right_bronze.push(i);
        if(right_bronze.size()>Z) {
            int tt=right_bronze.top();
            right_bronze.pop();
            ret-=p[tt].z;
            ret+=p[tt].y;
            in_silver[tt]=true;
        }
    }
    ll cur=ret;
    for(int i=X; i<X+Z; i++) {
        ll tmp=cur;
        tmp+=p[i].x;
        left_gold.push(i);
        int tt=left_gold.top();
        left_gold.pop();
        tmp-=p[tt].x;
        tmp+=p[tt].z;
        if(in_silver[i]) {
            tmp-=p[i].y;
            while(!right_bronze.empty()) {
                int tt=right_bronze.top();
                if(tt<=i) {
                    right_bronze.pop();
                } else {
                    right_bronze.pop();
                    in_silver[tt]=true;
                    tmp-=p[tt].z;
                    tmp+=p[tt].y;
                    break;
                }
            }
        } else {
            tmp-=p[i].z;
        }
        ret=max(ret,tmp);
        cur=tmp;
    }
    cout<<ret<<endl;
    return 0;
}