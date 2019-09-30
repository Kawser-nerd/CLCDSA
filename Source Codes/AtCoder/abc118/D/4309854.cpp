#include<iostream>
#include<bitset>
#include<string>
#include<cmath>
#include<vector>
#include<tuple>
using namespace std;
//# Functions for Vector/Matrix
template <typename T>
vector<T> zeros(int length){
    vector<T> vec(length, 0);
    return vec;
}
template <typename T>
vector<vector<T>> zeros(tuple<int, int> dim){
    vector<vector<T>> mat(get<0>(dim), vector<T>(get<1>(dim), 0));
    return mat;
}
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define VARNAME(VariableName) # VariableName
template <typename T>
void show(vector<T> &vec){
    cerr << VARNAME(vec) << ": " << endl;
    for (auto value : vec) {
        cerr << value << " ";
    }
    cerr << endl;
}
template <typename T>
void show(vector<vector<T>> &mat){
    for (auto vec : mat) {
        show(vec);
    }
}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(ALL(a))
#define RSORT(a) sort(RALL(a))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
bool iseven(int x){ return x % 2 == 0; }
bool isodd(int x){ return !iseven(x); }
int dist(int x, int y) { return abs(x - y);}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
	// cin.tie(0);
   	// ios::sync_with_stdio(false);
    // N: ??????M: ???????????
    // Ex. 20 4
    int N, M; cin >> N >> M;
    // A: ????????
    // Ex. 3 7 8 4
    VI A(M); REP(i, M) cin >> A[i];
    RSORT(A);
    show(A);
    // ??????????????????0????
    //           1,2,3,4,5,6,7,8,9
    VI cost = {0,2,5,5,4,5,6,3,7,6};
    // ???? i ?????????????????????????????
    VI dp(N+1, (int)-1e9);
    dp[0] = 0;
    FOR(i, 1, N+1){
        for(auto& j: A){
            // i?????????????????
            // j ?A????dp[i - cost[j]]???????????
            // ?????j???????????????
            if(i - cost[j] >= 0) dp[i] = max(dp[i], dp[i - cost[j]]+1);
        }
    }
    // N??????????????????dp[N]?????????????????
    // ???????????????????????????????????
    int n = N; // ???????
    string ans; // ??????
    while(n > 0){
        // n?????????????????????????
        int a; // ???????
        for(auto& j: A){
            // ??j???????????????????
            if((n - j >= 0) and (dp[n - cost[j]] == dp[n] - 1)){
                a = j;
                break;
            }
        }
        n -= cost[a];
        ans += '0' + a;
    }
    cout << ans;
    return 0;
}