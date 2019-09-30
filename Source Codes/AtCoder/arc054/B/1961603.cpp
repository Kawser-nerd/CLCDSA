#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30)
#define INFl (ll)5e15
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//????????
double P;
double calc(double x){
    return P / pow(2,x/1.5) + x;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> P;

    double s = 0.0,t = 1e2;
    while(true){
        double d1 = s + (t-s)/3;
        double d2 = s + 2 * (t-s)/3;
        double f1 = calc(d1);
        double f2 = calc(d2);
        if(f1 > f2){
            s = d1;
        }else{
            t = d2;
        }
        if(abs(f1 - f2) < 1e-9){
            printf("%.9lf\n",f1);
            return 0;
        }
    }

//    cout << s << endl;


    return 0;
}