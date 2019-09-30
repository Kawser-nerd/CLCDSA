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
int rui[52][52];
int N;
int cal(int sh,int sw,int th,int tw){
    th = min(th,N);
    tw = min(tw,N);
    sh++;
    sw++;
    return rui[th][tw] - rui[th][sw-1] - rui[sh-1][tw] + rui[sh-1][sw-1];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    vector<vector<int> > v(50,vector<int>(50,0));
    rep(i,0,N){
        rep(j,0,N){
            cin >> v[i][j];
            rui[i+1][j+1] += v[i][j];
            rui[N+1][N+1] += v[i][j];
            rui[i+1][N+1] -= v[i][j];
            rui[N+1][j+1] -= v[i][j];
        }
    }
    rep(i,0,N+1){
        rep(j,0,N+1){
            rui[i][j + 1] += rui[i][j];
        }
    }
    rep(i,0,N+1){
        rep(j,0,N+1){
            rui[i + 1][j] += rui[i][j];
        }
    }
    int Q;
    cin >> Q;
    rep(i,0,Q){
        int P;
        cin >> P;
        int ans = 0;
        for(int j = 1; j * j <= P; j++){
            int h = j;
            int w = P / j;
            for(int sh = 0; sh < N; sh++){
                for(int sw = 0; sw < N; sw++){
                    int kouho = 0;
//                    for(int lh = sh; lh < sh + h && lh < N; lh++){
//                        for(int lw = sw; lw < sw + w && lw < N; lw++){
//                            kouho += v[lh][lw];
//                        }
//                    }
                    kouho = cal(sh,sw,sh+h,sw+w);
                    ans = max(kouho,ans);
                }
            }
            swap(h,w);
            for(int sh = 0; sh < N; sh++){
                for(int sw = 0; sw < N; sw++){
                    int kouho = 0;
//                    for(int lh = sh; lh < sh + h && lh < N; lh++){
//                        for(int lw = sw; lw < sw + w && lw < N; lw++){
//                            kouho += v[lh][lw];
//                        }
//                    }
                    kouho = cal(sh,sw,sh+h,sw+w);
                    ans = max(kouho,ans);
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}