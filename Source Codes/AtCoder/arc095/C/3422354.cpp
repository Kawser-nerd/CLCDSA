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
typedef pair<char, char> PC;

const int INF = 1e15;
const int MOD = 1e9+7;

class pair_combination{
    private:
        int n;
        vector<bool> used;
        vector<P> tmp;
        vector<vector<P>> pairs;

        void make(int p, int fst){
            if((int)tmp.size() == n / 2){
                pairs.push_back(tmp);
                /*
                rep(i, (int)tmp.size()){
                    cout << tmp[i].first << " " << tmp[i].second << ", ";
                }
                cout << endl;
                */
                return;
            }

            if(used[p]){
                return;
            }
            used[p] = true;

            for(int i = p+1; i < n; i++){
                if(used[i]){
                    continue;
                }
                used[i] = true;
                tmp.emplace_back(p, i);
                int next;
                for(next = fst; next < n; next++){
                    if(not used[next]){
                        break;
                    }
                }
                make(next, fst);
                used[i] = false;
                tmp.pop_back();
            }
            used[p] = false;
        }

    public:
        pair_combination(int n)
            :n(n), used(n, false){
                if(n % 2 == 0){
                    make(0, 0);
                }else{
                    used[0] = true;
                    make(1, 0);
                    used[0] = false;
                    for(int i = 1; i < n; i++){
                        used[i] = true;
                        make(0, 0);
                        used[i] = false;
                    }
                }
            }

        vector<vector<P>> get_pairs(){
            return pairs;
        }
};

signed main(){
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> s[i][j];
        }
    }

    pair_combination pc(h);
    vector<vector<P>> p = pc.get_pairs();

    rep(i, (int)p.size()){
        vector<int> pos(h);
        vector<bool> usedP(h, false);
        rep(j, (int)p[i].size()){
            pos[j] = p[i][j].first;
            pos[h-1-j] = p[i][j].second;
            usedP[pos[j]] = true;
            usedP[pos[h-1-j]] = true;
        }

        if(h % 2 == 1){
            int unused;
            rep(i, h){
                if(not usedP[i]){
                    unused = i;
                }
            }
            pos[h/2] = unused;
        }

        vector<string> rows(w);
        rep(j, w){
            rep(k, h){
                rows[j].push_back(s[pos[k]][j]);
            }
        }

        vector<bool>used(w, false);
        rep(j, w){
            if(used[j]){
                continue;
            }

            rep(k, w){
                if(used[k]){
                    continue;
                }
                if(j == k){
                    continue;
                }
                string tmp = rows[k];
                reverse(tmp.begin(), tmp.end());
                if(rows[j] == tmp){
                    used[j] = true;
                    used[k] = true;
                    break;
                }
            }
        }

        int cnt = 0;
        int idx = 0;
        rep(j, w){
            if(not used[j]){
                cnt++;
                idx = j;
            }
        }

        bool ok = cnt == 0;
        if(cnt == 1){
            string tmp = rows[idx];
            reverse(tmp.begin(), tmp.end());
            if(rows[idx] == tmp){
                ok = true;
            }
        }

        if(ok){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}