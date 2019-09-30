#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi vec(n);
    set<int> s;
    int over3200 = 0;
    rep(i, n){
        cin >> vec[i];
        int unko = vec[i] / 400;
        if(unko >= 8){
            s.insert(8);
            over3200++;
        }else{
            s.insert(vec[i] / 400);
        }
    }
    if(over3200 == 0){
        cout << s.size() << ' ' << s.size() << endl;
    }else{
        if(s.size() == 1){
            cout << s.size() << ' ';
        }else{
            cout << s.size() - 1 << ' ';
        }
        int tmp = s.size() + over3200 - 1;
        cout << tmp << endl;

    }

    return 0;
}