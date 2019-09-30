#include<cstdio>
#include<map>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){
        int a,n;cin>>n;
        vector<int> v;
        REP(i,n){
                cin >> a;v.push_back(a);
        }
        sort(v.begin(),v.end());
        int ans = v.back()-v.front();
        cout << ans << endl;
        return 0;
}