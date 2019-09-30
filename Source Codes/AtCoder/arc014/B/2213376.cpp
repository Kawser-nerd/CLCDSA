#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    int n;
    cin >> n;


    set<string> list;
    bool win = true;;
    string s;
    cin >> s;
    list.insert(s);
    string before = s;
    rep(i, n-1){
        string s;
        cin >> s;

        if(list.find(s) != list.end() || s[0] != before[before.size()-1]){
            if(win){
                cout << "WIN" << endl;
                return 0;
            }else{
                cout << "LOSE" << endl;
                return 0;
            }
        }
        list.insert(s);
        win = not win;
        before = s;
    }
    cout << "DRAW" << endl;
    return 0;
}