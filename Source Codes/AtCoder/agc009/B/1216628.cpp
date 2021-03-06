#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
 
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (signed)((a).size())
#define EACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
 
using namespace std;
 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
 
const int MOD = 1000000007;
 
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"  << " " << __FILE__ << endl;
 
VI deps;
VVI edge;
 
int fn(int t){
    if(edge[t].size()==0){
        return 0;
    }else{
        VI tdeps(edge[t].size());
        REP(i,edge[t].size()){
            tdeps[i] = fn(edge[t][i]);
        }
        SORT(tdeps);
        for (int i = 1; i <= edge[t].size(); ++i) {
            tdeps[edge[t].size()-i] += i;
        }
        SORT(tdeps);
        return tdeps[edge[t].size()-1];
    }
}
 
signed main(void) {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cin.tie(0);
 
    int n;
    cin >> n ;
    VI a(n);
    FOR(i,1,n){
        cin >> a[i];
        a[i]--;
    }
 
    deps.resize(n,-1);
    edge.resize(n,VI());
    FOR(i,1,n){
        edge[a[i]].push_back(i);
    }
 
    cout << fn(0) << endl;
 
    return 0;
}