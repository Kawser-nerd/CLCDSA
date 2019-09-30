#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

pair<string, vector<int>> convert(string s){
    int cnt = 0;
    string t;
    vector<int> v;
    for(int i = 0; i < s.size(); i++){
        cnt++;
        if(i == s.size() - 1 || s[i] != s[i + 1]){
            t += s[i];
            v.push_back(cnt);
            cnt = 0;
        }
    }
    return make_pair(t, v);
}

int main(){
    int T;
    cin >> T;
    for(int casenum = 1; casenum <= T; casenum++){
        printf("Case #%d: ", casenum);
        int N;
        cin >> N;
        vector<string> v(N);
        REP(i, N) cin >> v[i];
        set<string> check;
        vector< vector<int> > cnt;
        REP(i, N){
            pair<string, vector<int>> p = convert(v[i]);
            check.insert(p.first);
            cnt.push_back(p.second);
        }
        if(check.size() != 1){
            cout << "Fegla Won" << endl;
        }else{
            int res = 0;
            for(int i = 0; i < cnt[0].size(); i++){
                int min_sum = INT_MAX;
                for(int l = 0; l <= 200; l++){
                    int sum = 0;
                    for(int j = 0; j < cnt.size(); j++){
                        sum += abs(cnt[j][i] - l);
                    }
                    min_sum = min(min_sum, sum);
                }
                res += min_sum;
            }
            cout << res << endl;
        }
    }
    return 0;
}

