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

    vector<string> ans;
    rep(i, n){
        string s;
        string t = "";
        cin >> s;

        for(char c: s){
            if(c == 'b' || c == 'c' || c == 'B' || c == 'C'){
                t.push_back('1');
            }else if(c == 'd' || c == 'w' || c == 'D' || c == 'W'){
                t.push_back('2');
            }else if(c == 't' || c == 'j' || c == 'T' || c == 'J'){
                t.push_back('3');
            }else if(c == 'f' || c == 'q' || c == 'F' || c == 'Q'){
                t.push_back('4');
            }else if(c == 'l' || c == 'v' || c == 'L' || c == 'V'){
                t.push_back('5');
            }else if(c == 's' || c == 'x' || c == 'S' || c == 'X'){
                t.push_back('6');
            }else if(c == 'p' || c == 'm' || c == 'P' || c == 'M'){
                t.push_back('7');
            }else if(c == 'h' || c == 'k' || c == 'H' || c == 'K'){
                t.push_back('8');
            }else if(c == 'n' || c == 'g' || c == 'N' || c == 'G'){
                t.push_back('9');
            }else if(c == 'z' || c == 'r' || c == 'Z' || c == 'R'){
                t.push_back('0');
            }
        }
        if(t != ""){
            ans.push_back(t);
        }
    }

    for(int i = 0; i < (int)ans.size()-1; i++){
        cout << ans[i] << " ";
    }
    if((int)ans.size() > 0){
        cout << ans[(int)ans.size()-1];
    }
    cout << endl;

    return 0;
}