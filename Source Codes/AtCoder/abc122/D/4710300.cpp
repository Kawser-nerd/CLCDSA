#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

typedef long long ll;



using namespace std;

struct three{
    int a,b,c;
    ll ct;
};

ll DENOM=1000000007LL;

bool cnd3(int a, int b, int c){
    if (a==0 && b==1 && c==2 ) return false;
    if (a==0 && b==2 && c==1 ) return false;
    if (a==1 && b==0 && c==2 ) return false;
    return true;
}

bool cnd4(int a, int b, int c, int d){
    if (a==0 && b==1 && c==2 ) return false;
    if (b==0 && c==1 && d==2) return false;
    
    if (a==1 && b==0 && c==2 ) return false;
    if (a==0 && c==1 && d==2) return false;
    
    if (a==0 && b==2 && c==1 ) return false;
    if (b==1 && c==0 && d==2) return false;
    
    if (a==0 && b==1 && d==2) return false;
    if (b==0 && c==2 && d==1) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<three> bef, aft;
    for (int i=0; i<4;++i){
        for (int j=0; j<4;++j){
            for (int k=0; k<4;++k){
                three p = {i,j,k,0};
                if (cnd3(i,j,k)) p.ct=1;
                bef.push_back(p);
                aft.push_back(p);
            }
        }
    }
    for (int m=3; m<n; ++m){
        for (int i=0; i<aft.size(); ++i){
            aft[i].ct=0;
            if(!cnd3(aft[i].a, aft[i].b, aft[i].c)) continue;
            for(int j=0; j<bef.size(); ++j){
                if( bef[j].b!=aft[i].a || bef[j].c!=aft[i].b ) continue;
                if( cnd4(bef[j].a,bef[j].b,bef[j].c, aft[i].c)){
                    aft[i].ct += bef[j].ct;
                    aft[i].ct = aft[i].ct % DENOM;
                }
            }
        }
        bef = aft;
    }
    ll ret=0LL;
    for (auto it=aft.begin(); it != aft.end(); ++it){
        ret += it->ct;
        ret = ret % DENOM;
    }
    cout << ret << endl;
    return 0;
}