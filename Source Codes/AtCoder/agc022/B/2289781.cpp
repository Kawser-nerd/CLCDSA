#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
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

    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(n == 4){
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if(n == 5){
        cout << "2 5 20 30 63" << endl;
        return 0;
    }

    vector<int> ans;
    int i;
    for(i = 0; i < 5000; i++){
        ans.push_back(6 * i + 2);
        ans.push_back(6 * i + 3);
        ans.push_back(6 * i + 4);
        ans.push_back(6 * i + 6);
    }

    ans.erase(ans.begin()+n, ans.end());

    int sum = 0;
    rep(i, (int)ans.size()) sum += ans[i];

    //2 3 4 6 8 9 10 12
    if(sum % 6 == 2){
        ans.erase(ans.begin() + 4);
        ans.push_back(30000);
    }
    if(sum % 6 == 3){
        ans.erase(ans.begin() + 5);
        ans.push_back(30000);
    }
    if(sum % 6 == 5){
        ans.erase(ans.begin() + 5);
        ans.push_back(29998);
    }

    for(int i = 0; i < (int)ans.size() - 1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;

    return 0;
}