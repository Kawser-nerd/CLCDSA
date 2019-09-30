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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    vector<vector<int> > E(N,vector<int>());

    rep(i,0,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    vector<bool> used(N,false);
    vector<int> path;
    int pt = 0;
    rep(i,0,N){
        if(E[i].size() > 0){
            pt = i;
            break;
        }
    }

    while(true){
        bool cont = false;
        for(int next: E[pt]){
            if(!used[next]){
                pt = next;
                path.push_back(pt);
                used[next] = true;
                cont = true;
                break;
            }
        }
        if(!cont){
            break;
        }
    }

    pt = path[0];
    reverse(all(path));

    while(true){
        bool cont = false;
        for(int next: E[pt]){
            if(!used[next]){
                pt = next;
                path.push_back(pt);
                used[next] = true;
                cont = true;
                break;
            }
        }
        if(!cont){
            break;
        }
    }


    cout << path.size() << endl;
    rep(i,0,path.size()){
        cout << path[i] + 1;
        if(i != path.size()-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return 0;
}