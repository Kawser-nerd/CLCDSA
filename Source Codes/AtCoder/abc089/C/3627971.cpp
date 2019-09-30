#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 1000000000
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
typedef long long int ll;

#define ARRAY_MAX 505

int main(){

    ll n;
    cin >> n;
    map<char,ll> mp;

    REP(i,n){
        string tmp;
        cin >> tmp;
        if(tmp[0] != 'M' && tmp[0] != 'A' && tmp[0] != 'R' && tmp[0] != 'C' && tmp[0] != 'H'){
        
        }else{
            mp[tmp[0]-'A']++;
        }
    }

    vector<ll> arr;

    for(auto itr:mp){
        arr.push_back(itr.second);
    }
    /*REP(i,arr.size()){
        cout << arr[i] << endl;
    }*/

    ll ans = 0;
    if(arr.size() < 3){
        ans = 0;
    }else{

        for(int i = 0;i < 5;i++){
            for(int j = i+1;j < 5;j++){
                for(int k = j+1;k < 5;k++){
                    ans += arr[i]*arr[j]*arr[k];
                }
            }
        }
    }
    cout << ans << endl;
    




    return 0;
}