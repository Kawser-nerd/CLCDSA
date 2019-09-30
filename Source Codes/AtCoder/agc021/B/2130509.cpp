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
double dist(double x1,double y1,double x2, double y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<double> x(N),y(N);
    rep(i,0,N){
        cin >> x[i] >> y[i];
    }
    double R = 1e11;
    double pi = M_PI;
    int num = 2000000;
    vector<int> ans(N);

    for(int i = 0; i < num; i++){
        double X = R * cos(i * 2 * pi / num);
        double Y = R * sin(i * 2 * pi / num);
        double min_d = dist(X,Y,x[0],y[0]);
//        if(i % 10000 == 0){
//            cout << X << " " << Y << endl;
//        }
        int min_k = 0;

        rep(j,1,N){
            double tmp = dist(X,Y,x[j],y[j]);
            if(tmp < min_d){
                min_d = tmp;
                min_k = j;
            }
        }
        ans[min_k]++;
    }
    rep(i,0,N){
        printf("%.6f\n",1.0 * ans[i] / num);
    }


    return 0;
}