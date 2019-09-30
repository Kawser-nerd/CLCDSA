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
    string s;
    cin >> s;

    if(s == "Monday"){
        cout << 5 << endl;
    }else if(s == "Tuesday"){
        cout << 4 << endl;
    }else if(s == "Wednesday"){
        cout << 3 << endl;
    }else if(s == "Thursday"){
        cout << 2 << endl;
    }else if(s == "Friday"){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}