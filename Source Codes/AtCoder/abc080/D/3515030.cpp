#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int N,C;

int main(){
    cin >> N >> C;

    vector<pair<int, int> > st[31],st2[31];

    REP(i,N){
        int ss,tt,cc;
        cin >> ss >> tt >> cc;
        st[cc].push_back(make_pair(ss,tt));
    }
    FOR(i,1,C+1){
        sort(st[i].begin(),st[i].end());
    }
    FOR(i,1,C+1){
        int ss = -1;
        int tt = -1;
        REP(j,st[i].size()){
            if(ss == -1)ss=st[i][j].first;
            if(tt == -1){
                tt=st[i][j].second;
            }else{
                if(tt == st[i][j].first){
                    tt=st[i][j].second;
                }else{
                    st2[i].push_back(make_pair(ss,tt));
                    ss=st[i][j].first;
                    tt=st[i][j].second;
                }
            }
        }
        if(ss != -1)st2[i].push_back(make_pair(ss,tt));
    }

    // FOR(i,1,C+1){
    //     REP(j,st[i].size()){
    //         cout << st[i][j].first << " " << st[i][j].second << endl;
    //     }
    // }
    // FOR(i,1,C+1){
    //     REP(j,st2[i].size()){
    //         cout << st2[i][j].first << "  " << st2[i][j].second << endl;
    //     }
    // }

    int rec[300000] = {0};
//    FOR(i,300001)rec[i] = 0;

    FOR(i,1,C+1){
        REP(j,st2[i].size()){
            rec[st2[i][j].first * 2 - 1] += 1;
            rec[st2[i][j].second * 2] -= 1;
        }
    }

    // REP(i,30){
    //     cout << i << " " << rec[i] << endl;
    // }
    int ans = 0;
    REP(i,300000-1){
        rec[i+1] = rec[i+1] + rec[i];
        ans = max(ans, rec[i+1]);
    }

    // REP(i,30){
    //     cout << i << " " << rec[i] << endl;
    // }
    cout << ans << endl;

}