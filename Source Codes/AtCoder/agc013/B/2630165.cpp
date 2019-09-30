#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ne(n+1, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;

        ne[a].push_back(b);
        ne[b].push_back(a);
    }

    deque<int> path;
    set<int> p;

    path.push_back(1);
    path.push_back(ne[1][0]);
    p.insert(1);
    p.insert(ne[1][0]);

    while(true){
        set<int> first, last;
        for(int i : ne[path[0]]){
            first.insert(i);
        }

        for(int i : ne[path[path.size()-1]]){
            last.insert(i);
        }

        bool fCheck, lCheck;
        fCheck = lCheck = true;
        for(int i : first){
            if(p.find(i) == p.end()){
                fCheck = false;
                break;
            }
        }
        for(int i : last){
            if(p.find(i) == p.end()){
                lCheck = false;
                break;
            }
        }

        if(fCheck && lCheck){
            cout << path.size() << endl;
            for(int i = 0; i < (int)path.size()-1; i++){
                cout << path[i] << " ";
            }
            cout << path[(int)path.size()-1] << endl;
            return 0;
        }

        if(not fCheck){
            for(int i : first){
                if(p.find(i) != p.end()){
                    continue;
                }
                path.push_front(i);
                p.insert(i);
                break;
            }
        }

        if(not lCheck){
            for(int i : last){
                if(p.find(i) != p.end()){
                    continue;
                }
                path.push_back(i);
                p.insert(i);
                break;
            }
        }
    }

    return 0;
}