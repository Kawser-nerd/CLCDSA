#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> charPos(26, vector<int>());
    rep(i, n){
        charPos[s[i]-'a'].push_back(i+1);
    }
    rep(i, 26){
        charPos[i].push_back(INF);
    }

    vector<int> pos;
    vector<int> len(n+1);
    for(int i = n; i >= 0; i--){
        int far = 0;

        rep(c, 26){
            int lo = -1;
            int hi = charPos[c].size()-1;

            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(charPos[c][mid] > i){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }

            far = max(far, charPos[c][hi]);
        }

        if(far == INF){
            len[i] = 1;
            continue;
        }

        len[i] = len[far] + 1;
    }

    string ans = "";
    int current = 0;
    rep(i, len[0]){
        rep(c, 26){
            int lo = -1;
            int hi = charPos[c].size()-1;

            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(charPos[c][mid] > current){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }

            if(charPos[c][hi] == INF || len[charPos[c][hi]] + 1 == len[0] - i){
                current = charPos[c][hi];
                ans.push_back('a' + c);
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}