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
    int n;
    cin >> n;

    vector<int> nim;
    rep(i, n){
        int x, y, z;
        cin >> x >> y >> z;
        int minX, maxX, minY, maxY, minZ, maxZ;
        minX = minY = minZ = INF;
        maxX = maxY = maxZ = 0;

        int m;
        cin >> m;
        rep(j, m){
            int a, b, c;
            cin >> a >> b >> c;

            minX = min(minX, a);
            minY = min(minY, b);
            minZ = min(minZ, c);
            maxX = max(maxX, a);
            maxY = max(maxY, b);
            maxZ = max(maxZ, c);
        }

        if(minX > 0){
            nim.push_back(minX);
        }
        if(minY > 0){
            nim.push_back(minY);
        }
        if(minZ > 0){
            nim.push_back(minZ);
        }
        if(maxX < x - 1){
            nim.push_back(x - 1 - maxX);
        }
        if(maxY < y - 1){
            nim.push_back(y - 1 - maxY);
        }
        if(maxZ < z - 1){
            nim.push_back(z - 1 - maxZ);
        }
    }

    int ans = 0;
    rep(i, (int)nim.size()){
        ans ^= nim[i];
    }

    if(ans == 0){
        cout << "LOSE" << endl;
    }else{
        cout << "WIN" << endl;
    }

    return 0;
}