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

int WindRun(int Dis)
{
    double dis = static_cast<double>(Dis);
    dis /= 60;
    dis *= 10;
    dis = round(dis);
    dis /= 10;
    if (dis <= 0.2) return 0;
    else if (dis <= 1.5) return 1;
    else if (dis <= 3.3) return 2;
    else if (dis <= 5.4) return 3;
    else if (dis <= 7.9) return 4;
    else if (dis <= 10.7) return 5;
    else if (dis <= 13.8) return 6;
    else if (dis <= 17.1) return 7;
    else if (dis <= 20.7) return 8;
    else if (dis <= 24.4) return 9;
    else if (dis <= 28.4) return 10;
    else if (dis <= 32.6) return 11;
    else return 12;
}

string Orientation(int Deg, int Dis)
{
    double deg = static_cast<double>(Deg);
    deg /= 10;
    if (WindRun(Dis) == 0) return "C";
    else if (deg >= 11.25 && deg < 33.75) return "NNE";
    else if (deg >= 33.75 && deg < 56.25) return "NE";
    else if (deg >= 56.25 && deg < 78.75) return "ENE";
    else if (deg >= 78.75 && deg < 101.25) return "E";
    else if (deg >= 101.25 && deg < 123.75) return "ESE";
    else if (deg >= 123.75 && deg < 146.25) return "SE";
    else if (deg >= 146.25 && deg < 168.75) return "SSE";
    else if (deg >= 168.75 && deg < 191.25) return "S";
    else if (deg >= 191.25 && deg < 213.75) return "SSW";
    else if (deg >= 213.75 && deg < 236.25) return "SW";
    else if (deg >= 236.25 && deg < 258.75) return "WSW";
    else if (deg >= 258.75 && deg < 281.25) return "W";
    else if (deg >= 281.2 && deg < 303.75) return "WNW";
    else if (deg >= 303.75 && deg < 326.25) return "NW";
    else if (deg >= 326.25 && deg < 348.75) return "NNW";
    else return "N";
}

int main()
{
    int Deg, Dis;
    cin >> Deg >> Dis;
    cout << Orientation(Deg, Dis) << " " << WindRun(Dis) << endl;
    return 0;
}