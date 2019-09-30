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
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int p[100010];

int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    rep(i,n)p[a[i]]++;
    int cnt = 0;
    rep(i,100010){
        cnt += max(0,p[i]-1);
    }
    if(cnt%2==0){
        cout << n-cnt << endl;
    }else{
        cout << n-cnt-1 << endl;
    }
    return 0;
}