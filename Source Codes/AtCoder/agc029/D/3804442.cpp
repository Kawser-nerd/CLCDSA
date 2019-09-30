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
    int h,w,n;
    cin >> h >> w >> n;
    swap(h,w);
    vector<int> c(h+2);
    vector<set<int> > st(h+2);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        st[y].insert(x);
    }
    c[1] = 1;
    for(int i=2;i<=h;i++){
        int t = c[i-1]+1;
        if(st[i].size()!=0){
            auto p = st[i].lower_bound(t);
            if(p==st[i].end()){
                c[i] = t;
                if(c[i]==w){
                    break;
                }
            }
            if((*p)!=t){
                c[i] = t;
                if(c[i]==w){
                    break;
                }
            }else{
                t++;
                while(1){
                    p++;
                    if(p!=st[i].end()){
                        if(*p!=t){
                            c[i] = t;
                            break;
                        }
                    }else{
                        c[i] = t;
                        break;
                    }
                    t++;
                }
                if(c[i]==w){
                    break;
                }
            }
        }else{
            c[i] = t;
            if(c[i]==w){
                break;
            }
        }
    }
    //rep(i,h)cout << c[i+1] << endl;
    int ans = 10000000;
    for(int i=1;i<=h;i++){
        if(c[i]==0)break;
        if(st[i].size()==0){
            ans = min(ans,w);
        }else{
            auto p = st[i].lower_bound(c[i]);
            if(p==st[i].end()){
                ans = min(ans,w);
            }else{
                //cerr <<c[i] << " " << *p << endl;
                ans = min(ans,(*p)-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}