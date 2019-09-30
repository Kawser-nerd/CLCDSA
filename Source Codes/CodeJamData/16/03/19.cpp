#include<bits/stdc++.h>
using namespace std;
const int inf = 1000000001;
const int MOD = 1000000007;
typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())


int d[11];

bool ok(string &s) {
    FOR(b,2,10) {
        bool fb=false;
        FOR(j,2,1000) {
            Int rem = 0;
            FOR(i,0,sz(s)-1) rem=(b*rem+s[i]-'0')%j;
            if(rem==0) {
                d[b]=j;
                fb=true;
                break;
            }
        }
        if(!fb) return false;
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    int t;cin>>t;
    FOR(tt,1,t) {
        int len, cnt;
        cin>>len>>cnt;
        vector<string> ans;
        vector<vector<int> > d;
        for(;;) {
            string s="1";
            FOR(i,1,len-2) if(rand()&1) s+="1";else s+="0";
            s+="1";

            if(ok(s) && find(ans.begin(), ans.end(), s)==ans.end()) {
                ans.pb(s);
                vector<int> temp;
                FOR(i,2,10) temp.pb(::d[i]);
                d.pb(temp);
                cerr<<s<<endl;
            }

            if(sz(ans)==cnt) break;
        }

        cout<<"Case #"<<tt<<":\n";
        FOR(i,0,sz(ans)-1) {
            cout<<ans[i];
            FOR(j,0,sz(d[i])-1) cout<<" "<<d[i][j];
            cout<<endl;
        }
    }
}
