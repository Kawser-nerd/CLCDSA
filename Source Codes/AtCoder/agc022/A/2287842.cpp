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
#include <unordered_map>
#include <unordered_set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define mod 1000000007
#define show(n) cerr<<#n<<" = "<<n<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl

//????AtCoder??define
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pint = pair<int,int>;

const int INF = (1 << 30);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    set<char> have;
    rep(i,s.size()){
        have.insert(s[i]);
    }

    char n='a';
    if(s.size()==26){
        if(s=="zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
            return 0;
        }
        
        REV(i,0,s.size()-1){
            n=s[i];
            for(;islower(n);n++){
                if(have.find(n)==have.end()){
                    s[i]=n;
                    rep(j,i+1){
                        cout<<s[j];
                    }cout<<endl;
                    return 0;
                }
            }
            have.erase(s[i]);
        }

    }else{
        rep(i, 26){
            if(have.find(n)==have.end()){
                cout<<s<<n<<endl;
                return 0;
            }
            n++;
        }
    }

    return 0;
}