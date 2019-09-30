#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include <fstream>
#include <complex>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i <(b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a,value, sizeof(a))

#define ALL(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<LL> VI;
typedef pair<int, LL> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;

int A[MAX];

int main()
{
    //freopen("input.txt", "r", stdin);
    //ios::sync_with_stdio(false);cin.tie(NULL);
    
    int n;
    cin >> n;
    n *= 2;
    FOR(i, 0, n)
    cin >> A[i];
    
    sort(A, A + n);
    int res = 0;
    for(int i = n - 2; i >= 0; i -= 2)
        res += A[i];
    
    cout << res << endl;
    
}