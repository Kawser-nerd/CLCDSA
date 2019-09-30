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
template <typename T>
class Sum2d{
    vector<vector<T> > vv;
    unsigned xSize{};
    unsigned ySize{};
public:
    Sum2d(unsigned xSize, unsigned ySize){
        vector<vector<T> > vv(xSize + 2, vector<T> (ySize + 2));
        this->vv = vv;
        this->xSize = xSize + 2;
        this->ySize = ySize + 2;
    }
    void add(int x,int y,T value){
        x++;
        y++;
        this->vv[x][y] += value;
        this->vv[0][0] += value;
        this->vv[x][0] -= value;
        this->vv[0][y] -= value;
    }
    void set_sum(){
        for(int i = 0; i < xSize - 1; i++){
            for(int j = 0; j < ySize; j++){
                this->vv[i+1][j] += vv[i][j];
            }
        }
        for(int i = 0; i < xSize; i++){
            for(int j = 0; j < ySize - 1; j++){
                this->vv[i][j+1] += vv[i][j];
            }
        }
    }
    T calc(int sx,int sy,int tx,int ty){
        sx++;
        sy++;
        tx++;
        ty++;
        return this->vv[tx][ty] + this->vv[sx-1][sy-1] - this->vv[tx][sy-1] - this->vv[sx-1][ty];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    Sum2d<int> rui(N,N);
    rep(i,0,N){
        rep(j,0,N){
            int tmp;
            cin >> tmp;
            rui.add(i,j,tmp);
        }
    }
    rui.set_sum();
    int Q;
    cin >> Q;
    rep(i,0,Q){
        int P;
        cin >> P;
        int ans = 0;
        for(int sx = 0; sx < N; sx++){
            for(int sy = 0; sy < N; sy++){
                for(int j = 1; j * j <= P; j++){
                    int sa = j;
                    int sb = P / j;
                    sa--;
                    sb--;

                    int kouho = rui.calc(sx,sy,min(sx+sa,N-1),min(sy+sb,N-1));
                    ans = max(kouho,ans);
                    kouho = rui.calc(sx,sy,min(sx+sb,N-1),min(sy+sa,N-1));
                    ans = max(kouho,ans);
                }
            }
        }
        cout << ans << endl;
    }



    return 0;
}