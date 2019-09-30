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
int H, W;

bool choku_f(int h, int w) {
    if (h == 0) return true;
    return h != H - 1 && w % 2 == 0;
}

bool aoki_f(int h,int w){
    if(h == H - 1) return true;
    return h != 0 && w % 2 == 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W;
    vector<vector<char> > choku(H, vector<char>(W)), aoki(H, vector<char>(W));

    rep(i,0,H){
        rep(j,0,W){
            if(choku_f(i,j)){
                choku[i][j] = '#';
            }else{
                choku[i][j] = '.';
            }
            if(aoki_f(i,j)){
                aoki[i][j] = '#';
            }else{
                aoki[i][j] = '.';
            }
        }
    }
    rep(i,0,H){
        rep(j,0,W){
            char tmp;
            cin >> tmp;
            if(tmp == '#'){
                choku[i][j] = '#';
                aoki[i][j] = '#';
            }
        }
    }

    rep(i,0,H){
        rep(j,0,W){
            cout << choku[i][j];
        }
        cout << endl;
    }
    cout << endl;
    rep(i,0,H){
        rep(j,0,W){
            cout << aoki[i][j];
        }
        cout << endl;
    }
//    rep(i,0,H){
//        rep(j,0,W){
//            if(aoki[i][j] == '#' && choku[i][j] == '#') cout << '#';
//            else cout << '.';
//        }
//        cout << endl;
//    }
    return 0;
}