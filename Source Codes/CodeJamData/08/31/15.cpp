#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

vector<int> read(){
    vector<int> res;
    string s;
    getline(cin, s);
    stringstream r(s);
    for(int x;r>>x;res.push_back(x));
    return res;
}

int P,K,L;
vector<int> a;

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    for(int T=read()[0],tc=0;tc++<T;){
        long long res=0;
        {
            vector<int> tmp=read();
            P=tmp[0];
            K=tmp[1];
            L=tmp[2];
        }
        a=read();
        sort(a.rbegin(),a.rend());
        vector<int> c(K);
        for(int i=0;i<L;++i){
            int j=i%K;
            res+=(++c[j])*(long long)a[i];
        }
        printf("Case #%d: %I64d\n",tc,res);
    }
    return 0;
}
