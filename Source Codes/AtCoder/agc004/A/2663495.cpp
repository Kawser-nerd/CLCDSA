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

typedef pair<int, int> p;

const int inf = 1e15;
const int mod = 1e9+7;

signed main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> ans;
    ans.push_back(a * b);
    ans.push_back(b * c);
    ans.push_back(c * a);
    cout << *min_element(ans.begin(), ans.end()) << endl;

    return 0;
}