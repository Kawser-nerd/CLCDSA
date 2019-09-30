#include <array>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <tuple>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define PB push


#define MOD 1000000007LL
#define EPS 1e-10

LL N;
set<LL> s;

bool CheckIf753(LL number)
{
    vector<bool> ok(10);
    ok.assign(10, false);
    while (number > 0)
    {
        ok[number % 10] = true;
        number /= 10;
    }
    return ok[7] && ok[5] && ok[3];
}

void dfs(LL number, LL digitsNum)
{
    if (number > N) return;

    for (int i : {3, 5, 7, 0})
    {
        if (i == 0)
        {
            if (CheckIf753(number))
            {
                s.insert(number);
            }
        }
        else
        {
            dfs(number * 10 + i, digitsNum + 1);
        }
    }
}

int main()
{
    cin >> N;
    dfs(0, 0);
    cout << s.size() << endl;
    return 0;
}