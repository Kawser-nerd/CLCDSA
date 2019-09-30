#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    for(int i=a;i<=b;i++){
        string s = to_string(i);
        bool flag = 1;
        rep(i,2){
            if(s[i]!=s[4-i]){
                flag = 0;
            }
        }
        if(flag)ans++;
    }
    cout << ans << endl;
    return 0;
}